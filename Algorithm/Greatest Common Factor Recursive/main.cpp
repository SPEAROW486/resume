

#include <iostream>

int GCFR(int num1, int num2)
{
    // Euclidean algorithm
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return GCFR(num2, num1 % num2);
    }
}

int main()
{
    constexpr int NUM1 = 280;
    constexpr int NUM2 = 30;

    std::cout << "Greatest Common Factor = " << GCFR(NUM1, NUM2);
    return 0;
}