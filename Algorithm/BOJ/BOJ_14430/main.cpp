
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14430
// 1,1 -> n,m

// DP로 ㄱㄱ

constexpr int MAX = 301;
int n, m;
int adj[MAX][MAX];
int ans = 0;

int dp[MAX][MAX];

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> adj[i][j];
        }
    }

    dp[1][1] = adj[1][1];

    // 점화식이 뭘까 오른쪽또는 아래로만 한칸되니까
    // dp[i][j+1], dp[i+1][j]

    // 반대로 생각하면

    // dp[i][j]에 도달할수있는 방법은 dp[i-1][j]랑 dp[i][j-1]인거지

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // 위에서 온 경로, 좌측에서 온 경로중 큰 채굴량 선택
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            if (adj[i][j] != 0)
            {
                // 현재 타일이 채굴량이 0이 아니면 더해줌
                dp[i][j] += adj[i][j];
            }
        }
    }

    std::cout << dp[n][m] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}