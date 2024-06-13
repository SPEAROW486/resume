
#include <bits/stdc++.h>

int factorial(int n)
{
    int result = 1;
    for (int i = n; i > 0; --i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << factorial(n) / (factorial(k) * factorial(n - k));
    return 0;
}