
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1000001;
constexpr int MOD = 15746;

int n;
int dp[MAX];

int main()
{
    FASTIO;

    std::cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
    }

    std::cout << dp[n];

    // int nn;
    // std::cin >> nn;
    return 0;
}