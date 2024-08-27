
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;
constexpr int MAX = 10001;
long long fibo[10001];

int main()
{
    FASTIO;
    fibo[1] = fibo[2] = 1;

    std::cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        int p, q;
        std::cin >> p >> q;
        for (int j = 3; j <= p; ++j)
        {
            fibo[j] = fibo[j - 1] + fibo[j - 2];
            fibo[j] %= q;
        }

        std::cout << "Case #" << i << ": " << fibo[p] % q << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}