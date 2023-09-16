#include <iostream>

int main()
{
    int record = 0;
    std::cin >> record;

    if (record >= 90)
    {
        std::cout << "A" << std::endl;
    }
    else if (record >= 80)
    {
        std::cout << "B" << std::endl;
    }
    else if (record >= 70)
    {
        std::cout << "C" << std::endl;
    }
    else if (record >= 60)
    {
        std::cout << "D" << std::endl;
    }
    else
    {
        std::cout << "F" << std::endl;
    }

    return 0;
}