#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1309

constexpr int MAX = 100001;
constexpr int MOD = 9901;

int dp[MAX][3]; // 0 = 배치하지 않음, 1은 왼쪽에 배치 2는 오른쪽에 배치했을 때
int n;

int main()
{
    FASTIO;
    std::cin >> n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    std::cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}
