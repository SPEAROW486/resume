
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 17;

int n;

int board[MAX][MAX];
int dp[MAX][MAX][3]; //  dp[i][j] 위치에 어떤 방식으로 파이프를 놓을 수 있는지

constexpr int HORIZON = 0;
constexpr int VERTICAL = 1;
constexpr int DIAGONAL = 2;

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    dp[1][2][HORIZON] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (board[i][j] == 1)
            {
                continue;
            }

            // 가로 -> 가로
            if (j + 1 <= n && board[i][j + 1] == 0)
            {
                dp[i][j + 1][HORIZON] += dp[i][j][HORIZON];
            }

            // 가로 -> 대각선
            if (j + 1 <= n && i + 1 <= n && board[i + 1][j] == 0 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 0)
            {
                dp[i + 1][j + 1][DIAGONAL] += dp[i][j][HORIZON];
            }

            // 세로 -> 세로
            if (i + 1 <= n && board[i + 1][j] == 0)
            {
                dp[i + 1][j][VERTICAL] += dp[i][j][VERTICAL];
            }

            // 세로 -> 대각선
            if (j + 1 <= n && i + 1 <= n && board[i + 1][j] == 0 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 0)
            {
                dp[i + 1][j + 1][DIAGONAL] += dp[i][j][VERTICAL];
            }

            // 대각선 -> 가로
            if (j + 1 <= n && board[i][j + 1] == 0)
            {
                dp[i][j + 1][HORIZON] += dp[i][j][DIAGONAL];
            }

            // 대각선 -> 세로
            if (i + 1 <= n && board[i + 1][j] == 0)
            {
                dp[i + 1][j][VERTICAL] += dp[i][j][DIAGONAL];
            }

            // 대각선 -> 대각선
            if (j + 1 <= n && i + 1 <= n && board[i + 1][j] == 0 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 0)
            {
                dp[i + 1][j + 1][DIAGONAL] += dp[i][j][DIAGONAL];
            }
        }
    }

    std::cout << dp[n][n][HORIZON] + dp[n][n][VERTICAL] + dp[n][n][DIAGONAL];

    // int nn;
    // std::cin >> nn;

    return 0;
}