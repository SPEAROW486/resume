

#include <iostream>

int Fibonacci(int num)
{
    return num <= 1 ? num : Fibonacci(num - 2) + Fibonacci(num - 1);
}

int main()
{
    std::cout << "Fibonacci 4 = " << Fibonacci(4) << std::endl;

    return 0;
}