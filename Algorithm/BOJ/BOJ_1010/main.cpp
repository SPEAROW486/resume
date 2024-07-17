
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 31;
int dp[MAX][MAX]; // dp[i][j] : i다리의 개수 , j 다리의 개수일때 i 개수만큼 다리를 놓을 수 있는 경우의 수

int main()
{
    FASTIO;

    int tc;
    std::cin >> tc;

    // 1 2 3 4 중에서 2개를 고르는 방법은
    // 1을 포함하고 2,3,4 중에서 1개씩 고르는 방법이랑
    // 1을 포함하지 않고 2,3,4 중에서 2개씩 고르는 방법의 합이랑 같음.
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            if (j == 0 || j == i)
            {
                // 아무것도 고르지않거나, 전부 고르거나 하는 케이스는 1개밖에 존재하지 않음.
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    while (tc--)
    {
        int n, m;
        std::cin >> n >> m;

        std::cout << dp[m][n] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}