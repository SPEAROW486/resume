#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int sign = -1;
    int bias = n;
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        for (int forward_star = 0; forward_star < n - bias; ++forward_star)
        {
            std::cout << " ";
        }

        for (int j = 0; j < 2 * bias - 1; ++j)
        {
            std::cout << "*";
        }

        if (bias == 1)
        {
            sign *= -1;
        }

        bias += sign;

        std::cout << std::endl;
    }
    return 0;
}