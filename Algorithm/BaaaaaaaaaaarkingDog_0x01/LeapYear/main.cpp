#include <iostream>

int main()
{
    int year = 0;
    std::cin >> year;

    // 4의 배수면서 100의 배수가 아닐때
    if (year % 4 == 0 && !(year % 100 == 0))
    {
        std::cout << 1;
    }
    else if (year % 400 == 0)
    {
        // 400의 배수일때
        std::cout << 1;
    }
    else
    {
        std::cout << 0;
    }
    return 0;
}