
#include <bits/stdc++.h>

constexpr int MAX = 1000001;
int buf[MAX];

int moduler = 1000000007;

int Fibonacci(int n)
{
    buf[0] = 0;
    buf[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        buf[i] = (buf[i - 2] + buf[i - 1]) % moduler;
    }

    return buf[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << Fibonacci(n);

    // int nn;
    // std::cin >> nn;

    return 0;
}