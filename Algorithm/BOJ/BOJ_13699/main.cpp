
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MAX = 36;
long long dp[MAX];
int main()
{
    FASTIO;

    std::cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    std::cout << dp[n] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}