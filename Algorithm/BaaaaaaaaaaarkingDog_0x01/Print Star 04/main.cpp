#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = n; i > 0; --i)
    {
        for (int k = 0; k < n - i; ++k)
        {
            std::cout << " ";
        }

        for (int j = 0; j < i; ++j)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}