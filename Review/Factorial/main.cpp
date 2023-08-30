

#include <iostream>

int Factorial(int N)
{
    return N <= 1 ? 1 : N * Factorial(N - 1);
}

int main()
{
    std::cout << Factorial(4);

    return 0;
}