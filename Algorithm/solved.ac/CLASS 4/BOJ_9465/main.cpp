
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 100001; // 100001;

int board[2][MAX];
int dp[2][MAX];
int n;

int main()
{
    // FASTIO;
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cin >> board[i][j];
            }
        }

        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];

        if (n > 1)
        {
            dp[0][1] = dp[1][0] + board[0][1];
            dp[1][1] = dp[0][0] + board[1][1];
        }

        for (int i = 2; i < n; ++i)
        {
            dp[0][i] = std::max(dp[1][i - 1], dp[1][i - 2]) + board[0][i];
            dp[1][i] = std::max(dp[0][i - 1], dp[0][i - 2]) + board[1][i];
        }

        std::cout << *std::max_element(&dp[0][0], &dp[1][MAX]) << "\n";
        std::fill(&dp[0][0], &dp[1][MAX], 0);
    }
    int nn;
    std::cin >> nn;

    return 0;
}