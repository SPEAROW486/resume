#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int sign = 1;
    int bias = 1;
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        for (int forward_space = 0; forward_space < n - bias; ++forward_space)
        {
            std::cout << " ";
        }

        for (int j = 0; j < 2 * bias - 1; ++j)
        {
            std::cout << "*";
        }

        if (bias == n)
        {
            sign *= -1;
        }

        bias += sign;

        std::cout << std::endl;
    }
    return 0;
}