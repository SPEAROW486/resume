#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 10164

int n, m;
long long dp[16][16];

int main()
{
    FASTIO;
    int n, m, k, cx, cy, cnt = 0;
    std::cin >> n >> m >> k;
    dp[1][1] = 1;

    // DP 테이블 초기화 및 계산
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }

    if (k != 0)
    {
        if (k % m != 0)
        {
            cy = k % m;
            cx = (k - cy) / m + 1;
        }
        else
        {
            cx = k / m;
            cy = m;
        }
    }

    if (k == 0)
    {
        std::cout << dp[n][m];
    }
    else
    {
        std::cout << dp[cx][cy] * dp[n - cx + 1][m - cy + 1];
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
