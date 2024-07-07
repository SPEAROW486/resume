
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int NMAX = 101;   // 101;
constexpr int MAX = 100001; // 100001;
int n, k;
int dp[NMAX][MAX];

int weight[NMAX];
int value[NMAX];

int main()
{
    FASTIO;
    std::cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        int w, v;
        std::cin >> w >> v;

        weight[i] = w;
        value[i] = v;

        dp[i][w] = v;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (weight[i] > j)
            {
                // 담을수 없으면 이전 물건까지 고려한 그대로
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // i-1번째 물건까지 담아서 j무게를 채울때랑
                // i번째 물건까지 담아서 j무게를 채울때니까
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    std::cout << dp[n][k];

    // int nn;
    // std::cin >> nn;

    return 0;
}