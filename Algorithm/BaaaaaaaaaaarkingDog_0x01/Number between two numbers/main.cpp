#include <iostream>

int main()
{
    long long a, b;

    std::cin >> a >> b;

    if (a > b)
    {
        std::swap(a, b);
    }

    if (a != b)
    {
        std::cout << b - a - 1 << std::endl;
        for (long long i = a + 1; i < b; ++i)
        {
            std::cout << i << " ";
        }
    }
    else
    {
        std::cout << 0;
    }

    return 0;
}