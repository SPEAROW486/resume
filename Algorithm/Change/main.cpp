#include <iostream>
int main()
{
    int change = 1610; // 거스름돈

    int coins[4] = {10, 50, 100, 500};
    for (int i = 3; i >= 0; --i)
    {
        int count = change / coins[i];
        if (count > 0)
        {
            std::cout << coins[i] << " : " << count << std::endl;
            change = change % coins[i];
        }
    }
    return 0;
}