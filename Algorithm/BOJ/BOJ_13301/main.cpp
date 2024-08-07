
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 81;
long long fibo[MAX];

int main()
{
    FASTIO;

    int n;
    std::cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= n + 1; ++i)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    std::cout << (fibo[n + 1] + fibo[n]) * 2 << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}