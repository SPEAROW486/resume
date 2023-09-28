#include <iostream>
#include <algorithm>

int main()
{
    constexpr int BUFFER_SIZE = 9;

    int nums[BUFFER_SIZE];
    int sum = 0;
    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        std::cin >> nums[i];
        sum += nums[i];
    }

    constexpr int SUM_SEVEN_DWARFS = 100;
    int distance = sum - SUM_SEVEN_DWARFS;

    int fake_dwarf_1 = 0;
    int fake_dwarf_2 = 0;
    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        for (int j = i + 1; j < BUFFER_SIZE; ++j)
        {
            if (distance - nums[i] - nums[j] == 0)
            {
                fake_dwarf_1 = nums[i];
                fake_dwarf_2 = nums[j];
                break;
            }
        }
    }

    std::sort(nums, nums + BUFFER_SIZE);
    for (int elem : nums)
    {
        if (elem != fake_dwarf_1 && elem != fake_dwarf_2)
        {
            std::cout << elem << std::endl;
        }
    }

    return 0;
}