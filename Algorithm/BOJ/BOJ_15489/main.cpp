
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int r, c, w;

constexpr int MAX = 31;
int board[MAX][MAX];

int main()
{
    // FASTIO;

    std::cin >> r >> c >> w;

    // 1번째 줄에는 1개의 수만있음
    // i번째 줄에는 i개의 수만 있다는것.

    // r+w까지 파스칼 삼각형을 구성해야함.

    board[1][1] = 1;
    for (int i = 2; i < MAX; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (j == 1 || j == i)
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
            }
        }
    }

    // 반복범위를 조절하는식으로 가면 복잡하고
    // 반복 범위 자체는 그대로 두되
    // 인덱스에 바이아스를 더해주면 편함.
    int ans = 0;
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            ans += board[r + i][c + j];
        }
    }

    std::cout << ans;

    int nn;
    std::cin >> nn;

    return 0;
}