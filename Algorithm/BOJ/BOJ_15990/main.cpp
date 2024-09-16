
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 15990

constexpr int MAX = 100001;
constexpr int MOD = 1000000009;
long long dp[MAX][4]; // dp[i][j] == i는 목표숫자 j는 마지막에 사용한 숫자
int n;
int tc;

int main()
{
    FASTIO;

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i < MAX; ++i)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }

    std::cin >> tc;
    while (tc--)
    {
        std::cin >> n;

        std::cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}