

#include <iostream>

int main()
{
    constexpr int MAX = 1000;
    constexpr int num = 4;

    int sum = 0;
    int count = 0;

    for (int i = 0; i <= MAX; ++i)
    {
        if (i % num == 0)
        {
            sum += i;
            count++;
        }
    }

    std::cout << num << " Multiple Count : " << count << " Multiple Sum : " << sum << std::endl;
    return 0;
}