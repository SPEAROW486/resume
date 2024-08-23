
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MAX = 117;
long long fibo[MAX];

int main()
{
    // FASTIO;

    std::cin >> n;

    fibo[1] = fibo[2] = fibo[3] = 1;
    for (int i = 4; i <= n; ++i)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 3];
    }

    std::cout << fibo[n];

    int nn;
    std::cin >> nn;

    return 0;
}