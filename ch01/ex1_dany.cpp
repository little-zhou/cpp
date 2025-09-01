#include <iostream>

int main()
{
    int original_var = 100; // 声明一个整型变量 original_var

    // 声明一个对 original_var 的引用 ref_var
    // int& 表示 ref_var 是一个对 int 类型的引用
    int &ref_var = original_var; // ref_var 现在是 original_var 的别名

    std::cout << "original_var 的值: " << original_var << std::endl; // 输出：original_var 的值: 100
    std::cout << "ref_var 的值: " << ref_var << std::endl;           // 输出：ref_var 的值: 100

    ref_var = 200;                                                                       // 通过引用修改 original_var 的值
    std::cout << "通过 ref_var 修改后 original_var 的值: " << original_var << std::endl; // 输出：...: 200

    std::cout << "original_var 的地址: " << &original_var << std::endl; // 地址相同
    std::cout << "ref_var 的地址: " << &ref_var << std::endl;           // 地址相同

    // int& another_ref; // 错误：引用必须在声明时初始化
    // int another_var = 300;
    // ref_var = another_var; // 这不是重新绑定，而是将 another_var 的值赋给 original_var
    // std::cout << "ref_var = another_var 后的 original_var 值: " << original_var << std::endl;
    // 此时 original_var 变为 300，ref_var 仍然是 original_var 的别名

    int c = original_var;
    std::cout << "c address: " << &c << std::endl;

    return 0;
}