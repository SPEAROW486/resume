#include <iostream>
#include <limits>

int main()
{
    constexpr int BUFFER_SIZE = 7;

    int nums[BUFFER_SIZE];

    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        std::cin >> nums[i];
    }

    int odd_number_sum = 0;
    int odd_number_min = std::numeric_limits<int>::max();

    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        if (nums[i] % 2 != 0)
        {
            odd_number_sum += nums[i];

            if (nums[i] < odd_number_min)
            {
                odd_number_min = nums[i];
            }
        }
    }

    if (odd_number_sum == 0)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << odd_number_sum << std::endl;
        std::cout << odd_number_min << std::endl;
    }

    return 0;
}