#include <iostream>
#include <cstring>

const char str1[] = "hello";
const char str2[] = "world!";

int main()
{
    constexpr size_t new_size = strlen(str1) + strlen(" ") + strlen(str2) + 1;
    char str3[new_size];

    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);

    std::cout << str3 << std::endl;

    return 0;
}