

#include <iostream>

int main()
{
    constexpr int LINE_COUNT = 5;
    constexpr int DATA_MAX = 25;
    constexpr int DATA_COUNT = DATA_MAX / LINE_COUNT;

    for (int line = 1; line <= LINE_COUNT; ++line)
    {
        if (line % 2 == 0)
        {
            for (int i = line * DATA_COUNT; i >= (line - 1) * DATA_COUNT + 1; --i)
            {
                std::cout << i << " ";
            }
        }
        else
        {
            for (int i = (line - 1) * DATA_COUNT + 1; i <= line * DATA_COUNT; ++i)
            {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}