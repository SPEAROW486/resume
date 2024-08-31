#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 8;
constexpr int INF = 1e9;
int board[MAX][MAX];
int n, m;

int dp[MAX][MAX][3]; // dp[i][j] = dp[i][j]까지 도달하기 위한 최소 연료, 그리고 방향?

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int d = 0; d < 3; ++d)
            {
                dp[i][j][d] = INF;
            }
        }
    }

    for (int j = 0; j < m; ++j)
    {
        for (int d = 0; d < 3; ++d)
        {
            dp[0][j][d] = board[0][j];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (j > 0)
            { // 왼쪽 대각선 위에서 오는 경우를 계산하기 위해 j > 0인지 확인
                dp[i][j][0] = std::min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + board[i][j];
            }
            dp[i][j][1] = std::min(dp[i - 1][j][0], dp[i - 1][j][2]) + board[i][j];
            if (j < m - 1)
            { // 오른쪽 대각선 위에서 오는 경우를 계산하기 위해 j < m - 1인지 확인
                dp[i][j][2] = std::min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + board[i][j];
            }
        }
    }

    int ans = INF;
    for (int j = 0; j < m; ++j)
    {
        for (int d = 0; d < 3; ++d)
        {
            ans = std::min(ans, dp[n - 1][j][d]);
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
