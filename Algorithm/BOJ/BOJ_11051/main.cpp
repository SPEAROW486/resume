
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 11051
// 단순히 NcR 문제는 아닐거같고 나머지 정리 + DP일 가능성이 있을듯.
// n,k가 1000 이하니까 매번 팩토리얼을 구하면 시간이 초과될려나 ?
// 일단 단순히 해볼까

int n, k;
constexpr int MAX = 1001;
constexpr int MOD = 10007;
long long dp[MAX][MAX];

int main()
{
    FASTIO;

    std::cin >> n >> k;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (j == 0 || i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            }
        }
    }

    std::cout << dp[n][k] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}