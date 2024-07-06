
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
constexpr int MAX = 1025; // 1025;

int dp[MAX][MAX]; // dp[i][j] => i,1부터 i,j까지의 구간합?
int board[MAX][MAX];

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    // 일단 1차적으로 i행에 j열까지만 구간합으로 만든다.
    //
    // 1 2 3 4 ----> 1, 3, 6, 10
    // 2 3 4 5 ----> 2, 5, 9, 14
    // 3 4 5 6 ----> 3, 7, 12, 18
    // 4 5 6 7 ----> 4, 9, 15, 22

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dp[i][j - 1] + board[i][j];
        }
    }

    // 그다음 dp[2][2]를 1,1부터 2,2까지 사각형으로 긁으려면
    // dp[2][2] = dp[2][2] + dp[1][2];
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dp[i][j] + dp[i - 1][j];
        }
    }

    // x2,y2까지의 전체 구간합에서 위 사각형, 옆 사각형 걷어내고, 걷어내면서 중복된 부분은 2번 빼기가 됬으니 한번 다시 더해줌.
    for (int i = 1; i <= m; ++i)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int x3 = x1 - 1;
        int y3 = y1 - 1;

        std::cout << dp[x2][y2] - dp[x3][y2] - dp[x2][y3] + dp[x3][y3] << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}