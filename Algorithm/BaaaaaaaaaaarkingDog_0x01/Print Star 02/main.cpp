#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int star_count = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n - 1 - i; ++k)
        {
            std::cout << " ";
        }

        for (int j = 0; j < star_count; ++j)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        ++star_count;
    }
    return 0;
}