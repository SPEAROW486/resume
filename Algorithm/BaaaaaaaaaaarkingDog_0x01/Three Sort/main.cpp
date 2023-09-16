#include <iostream>

int main()
{
    int nums[3];
    int tmp = 0;

    for (int i = 0; i < 3; ++i)
    {
        std::cin >> nums[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (nums[i] > nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        std::cout << nums[i] << " ";
    }

    return 0;
}