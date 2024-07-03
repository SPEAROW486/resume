#include <iostream>
#include <vector>

int Fibonacci(int n)
{
    std::vector<int> v(n + 2);
    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        v[i] = v[i - 1] + v[i - 2];
    }

    return v[n];
}

int main()
{
    std::cout << Fibonacci(10) << std::endl;
    return 0;
}