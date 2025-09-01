#include <iostream>
int main()
{
    int currVal = 0, val = 0;

    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << "Current var " << currVal << " occur " << cnt << " times." << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << "Current var " << currVal << " occur " << cnt << " times." << std::endl;
    }
    return 0;
}