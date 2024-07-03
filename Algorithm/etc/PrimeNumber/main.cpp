

#include <iostream>

int main()
{
    constexpr int MAX = 1000;

    int prime_count = 0;
    for (int i = 1; i <= MAX; ++i)
    {
        int divisor_count = 0;
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0)
            {
                divisor_count++;
            }
        }

        if (divisor_count == 0)
        {
            std::cout << i << " ";
            if (++prime_count % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "prime_count = " << prime_count;

    return 0;
}