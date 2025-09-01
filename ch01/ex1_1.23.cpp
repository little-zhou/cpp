#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    std::cout << "Please input your sales: " << std::endl;
    Sales_item currItem, valItem;
    if (std::cin >> currItem)
    {
        int cnt = 1;
        while (std::cin >> valItem)
        {
            if (currItem.isbn() == valItem.isbn())
            {
                ++cnt;
            }
            else
            {
                std::cout << currItem.isbn() << " has " << cnt << std::endl;
                currItem = valItem;
                cnt = 1;
            }
        }
        std::cout << currItem.isbn() << " has " << cnt << std::endl;
    }
    return 0;
}