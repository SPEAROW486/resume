#include <iostream>
#include <algorithm>

int main()
{
    int nums[9];

    for (int i = 0; i < 9; ++i)
    {
        std::cin >> nums[i];
    }

    int max = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    std::cout << max << std::endl;
    auto it = std::find(nums, nums + 8, max);
    std::cout << std::distance(nums, it) + 1 << std::endl;
    return 0;
}