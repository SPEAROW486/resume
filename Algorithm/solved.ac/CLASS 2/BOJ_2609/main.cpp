
#include <bits/stdc++.h>

int n, m;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    std::cin >> n >> m;

    int g = GCD(n, m);
    std::cout << g << "\n";
    std::cout << n * m / g << "\n";

    return 0;
}