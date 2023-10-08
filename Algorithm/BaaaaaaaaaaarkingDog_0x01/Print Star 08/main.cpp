#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int sign = 1;
    int bias = 1;
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        for (int forward_star = 0; forward_star < bias; ++forward_star)
        {
            std::cout << "*";
        }

        for (int j = 0; j < 2 * n - 2 * bias; ++j)
        {
            std::cout << " ";
        }

        for (int backward_star = 0; backward_star < bias; ++backward_star)
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