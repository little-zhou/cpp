"""
@Author: danyzhou
@Updated: 9/19/25 10:36 AM

Advantest Confidential - All Rights Reserved
"""

import torch
import torch.nn as nn
import math

from torch.nn.functional import dropout


class Embeddings(nn.Module):
    def __init__(self, vocab_size, d_model):
        super().__init__()
        self.embed = nn.Embedding(vocab_size, d_model)
        self.d_model = d_model

    def forward(self, x):
        res_org = self.embed(x)
        # print(res_org)
        res = self.embed(x) * math.sqrt(self.d_model)
        # print(x.size())
        # print(f'------------------')
        # print(res)
        return res

class PositionEncoding(nn.Module):
    def __init__(self, d_model, max_len=5000):
        super().__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len).unsqueeze(1).float()
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * -(math.log(10000.0) / d_model))

        pe[:, 0::2] = torch.sin(position / div_term)
        pe[:, 1::2] = torch.cos(position / div_term)

        pe = pe.unsqueeze(0)
        self.register_buffer('pe', pe)

    def forward(self, x):
        print(f'sadfffffffffffffffff--------------{x.size(1)}')
        return x + self.pe[:, :x.size(1)]


def attention(query, key, value, mask=None, dropout=None):
    """
    :param query:
        1 → batch_size
        4 → 序列长度 (seq_len) 4 or 5
        4 → 注意力头数 h = 4
        8 → 每个头的维度 (d_k)
            d_k = d_model/h = 32/4=8

    :param key:
    :param value:
    :param mask:
    :param dropout:
    :return:
    """
    d_k = query.size(-1)
    scores = query @ key.transpose(-2, -1) / math.sqrt(d_k)

    if mask is not None:
        scores = scores.masked_fill(mask == 0, float('-inf'))

    attn = torch.softmax(scores, dim=-1)

    if dropout:
        attn = dropout(attn)

    return attn @ value, attn


class MultiHeadAttention(nn.Module):
    def __init__(self, h, d_model, dropout=0.1):
        super().__init__()
        assert d_model % h == 0
        self.d_k = d_model // h
        self.h = h

        self.linear_q = nn.Linear(d_model, d_model)
        self.linear_k = nn.Linear(d_model, d_model)
        self.linear_v = nn.Linear(d_model, d_model)
        self.linear_out = nn.Linear(d_model, d_model)
        self.dropout = nn.Dropout(dropout)

    def forward(self, query, key, value, mask=None):
        batch_size = query.size(0)

        def transform(x, linear):
            x = linear(x)
            return x.view(batch_size, -1, self.h, self.d_k).transpose(1, 2)

        query = transform(query, self.linear_q)
        key = transform(key, self.linear_k)
        value = transform(value, self.linear_v)

        x, _ = attention(query, key, value, mask, self.dropout)

        x = x.transpose(1, 2).contiguous().view(batch_size, -1, self.h * self.d_k)

        return self.linear_out(x)


class FeedForward(nn.Module):
    def __init__(self, d_model, d_ff, dropout=0.1):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(d_model, d_ff),
            nn.ReLU(),
            nn.Linear(d_ff, d_model),
            nn.Dropout(dropout)
        )

    def forward(self, x):
        return self.net(x)


class AddNorm(nn.Module):
    def __init__(self, size, dropout=0.1):
        super().__init__()
        self.norm = nn.LayerNorm(size)
        self.dropout = nn.Dropout(dropout)

    def forward(self, x, sublayer):
        return x + self.dropout(sublayer(self.norm(x)))


class EncoderLayer(nn.Module):
    def __init__(self, d_model, self_attn, feed_forward, dropout):
        super().__init__()
        self.self_attn = self_attn
        self.feed_forward = feed_forward
        self.sublayers = nn.ModuleList(
            [
                AddNorm(d_model, dropout),
                AddNorm(d_model, dropout)
            ]
        )

    def forward(self, x, mask):
        x = self.sublayers[0](x, lambda y1: self.self_attn(x, x, x, mask))
        x = self.sublayers[1](x, lambda y2: self.feed_forward(x))
        return x


class DecoderLayer(nn.Module):
    def __init__(self, d_model, self_attn, cross_attn, feed_forward, dropout):
        super().__init__()
        self.self_attn = self_attn
        self.cross_attn = cross_attn
        self.feed_forward = feed_forward
        self.sublayers = nn.ModuleList(
            [
                AddNorm(d_model, dropout),
                AddNorm(d_model, dropout),
                AddNorm(d_model, dropout),
            ]
        )

    def forward(self, x, memory, src_mask, tag_mask):
        out1 = self.sublayers[0](x, lambda y1: self.self_attn(x, x, x, tag_mask))
        out2 = self.sublayers[1](out1, lambda  y2: self.cross_attn(out1, memory, memory, src_mask))
        out3 = self.sublayers[2](out2, lambda y3: self.feed_forward(out2))

        return out3


class Transformer(nn.Module):
    def __init__(self, src_vocab, tag_vocab, d_model=512, N=6, h=8, d_ff=2048, dropout=0.1):
        super().__init__()
        self.src_embed = nn.Sequential(
            Embeddings(src_vocab, d_model),
            PositionEncoding(d_model)
        )

        self.tag_embed = nn.Sequential(
            Embeddings(tag_vocab, d_model),
            PositionEncoding(d_model)
        )

        attn = lambda: MultiHeadAttention(h, d_model, dropout)
        ff = lambda: FeedForward(d_model, d_ff, dropout)

        self.encoder = nn.ModuleList([
            EncoderLayer(d_model, attn(), ff(), dropout) for _ in range(N)
        ])

        self.decoder = nn.ModuleList([
            # d_model, self_attn, cross_attn, feed_forward, dropout
            DecoderLayer(d_model, attn(), attn(), ff(), dropout) for _ in range(N)
        ])

        self.out = nn.Linear(d_model, tag_vocab)

    def encode(self, src, src_mask):
        x = self.src_embed(src)
        for layer in self.encoder:
            x = layer(x, src_mask)
        return x

    def decode(self, tag, memory, src_mask, tag_mask):
        x = self.tag_embed(tag)
        for layer in self.decoder:
            x = layer(x, memory, src_mask, tag_mask)
        return x

    def forward(self, src, tag, src_mask=None, tag_mask=None):
        memory = self.encode(src, src_mask)
        out = self.decode(tag, memory, src_mask, tag_mask)
        return self.out(out)





