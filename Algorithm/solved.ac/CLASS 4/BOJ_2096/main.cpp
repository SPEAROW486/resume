
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 100001; // 100001

int n;
int board[MAX][3];
int dp2_max[2][3];
int dp2_min[2][3];

int main()
{
    // 1. 백트래킹으로 풀었는데 예제는 통과하나 n이 너무커서 시간이 초과됨. n을 보고 백트래킹을 시도하면 안됬음.
    // 2. dp로 풀었는데 예제는 나오는데 메모리가 터짐.
    // 3. n-1, n번째 줄만 알면되니 dp 테이블을 dp[max][3] -> dp[2][3]으로 변경 후 이전값 저장해서 처리해서 정답
    // 토탈 한 30분 정도 걸린듯
    FASTIO;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        dp2_max[1][0] = std::max(dp2_max[0][0], dp2_max[0][1]) + board[i][0];
        dp2_max[1][1] = std::max({dp2_max[0][0], dp2_max[0][1], dp2_max[0][2]}) + board[i][1];
        dp2_max[1][2] = std::max(dp2_max[0][1], dp2_max[0][2]) + board[i][2];

        dp2_max[0][0] = dp2_max[1][0];
        dp2_max[0][1] = dp2_max[1][1];
        dp2_max[0][2] = dp2_max[1][2];

        dp2_min[1][0] = std::min(dp2_min[0][0], dp2_min[0][1]) + board[i][0];
        dp2_min[1][1] = std::min({dp2_min[0][0], dp2_min[0][1], dp2_min[0][2]}) + board[i][1];
        dp2_min[1][2] = std::min(dp2_min[0][1], dp2_min[0][2]) + board[i][2];

        dp2_min[0][0] = dp2_min[1][0];
        dp2_min[0][1] = dp2_min[1][1];
        dp2_min[0][2] = dp2_min[1][2];
    }

    std::cout << std::max({dp2_max[1][0], dp2_max[1][1], dp2_max[1][2]}) << " " << std::min({dp2_min[1][0], dp2_min[1][1], dp2_min[1][2]});

    // int nn;
    // std::cin >> nn;

    return 0;
}