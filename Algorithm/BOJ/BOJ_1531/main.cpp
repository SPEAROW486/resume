
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
int board[MAX][MAX];
int n, m;

int main()
{
    FASTIO;
    std::cin >> n >> m;

    while (n--)
    {
        int sx, sy, ex, ey;
        std::cin >> sx >> sy >> ex >> ey;
        for (int i = sx; i <= ex; ++i)
        {
            for (int j = sy; j <= ey; ++j)
            {
                ++board[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < MAX; ++i)
    {
        for (int j = 1; j < MAX; ++j)
        {
            if (board[i][j] > m)
            {
                ++ans;
            }
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}