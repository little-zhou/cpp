#include <iostream>

std::string global_str;
int global_int;
int a__b = 0;
int main()
{
    int local_int;
    std::string local_str;
    std::cout << global_str << " " << global_int << " " << local_int << " " << local_str << " " << std::endl;
    return 0;
}