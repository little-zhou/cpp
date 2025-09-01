#include <new>
int main()
{
    int *p1 = new int;
    int *p2 = new (std::nothrow) int;
    return 0;
}