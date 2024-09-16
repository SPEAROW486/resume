
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 15988

constexpr int MAX = 1000001;
constexpr int MOD = 1000000009;
long long dp[MAX];
int n;
int tc;

int main()
{
    FASTIO;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < MAX; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= MOD;
    }

    std::cin >> tc;
    while (tc--)
    {
        std::cin >> n;

        std::cout << dp[n] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}