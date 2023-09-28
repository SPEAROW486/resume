#include <iostream>
#include <algorithm>

int main()
{
    constexpr int BUFFER_SIZE = 5;

    int nums[BUFFER_SIZE];

    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        std::cin >> nums[i];
    }

    int average = 0;
    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        average += nums[i];
    }
    average /= BUFFER_SIZE;

    std::sort(nums, nums + BUFFER_SIZE);
    int median = nums[BUFFER_SIZE / 2];

    std::cout << average << std::endl;
    std::cout << median << std::endl;

    return 0;
}