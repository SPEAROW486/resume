

#include <iostream>

int main()
{
    constexpr int MAX_SIZE = 10;
    int Numbers[MAX_SIZE];
    memset(Numbers, 0, sizeof(Numbers));

    int *NumPtr = Numbers;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        *NumPtr = i;
        ++NumPtr;
    }

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        std::cout << Numbers[i] << std::endl;
    }

    return 0;
}