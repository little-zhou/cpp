// Print each number in the range specified by two integers.
#include <iostream>
using std::cin;
using std::cout;

// void print_range(int low, int high)
// {
//     if (low > high)
//     {
//         print_range(high, low);
//     }
//     else
//     {
//         for (int i = low; i <= high; i++)
//         {
//             cout << i << " ";
//         }
//     }
// }

void print_range(int low, int high)
{
    if (low > high)
    {
        print_range(high, low);
        return;
    }

    for (int i = low; i <= high; ++i)
    {
        cout << i << " ";
    }
}

int main()
{
    int low = 0, high = 0;
    cout << "Please input two int number: ";
    cin >> low >> high;
    print_range(low, high);
    return 0;
}
