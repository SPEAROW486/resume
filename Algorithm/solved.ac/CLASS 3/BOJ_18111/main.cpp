
#include <bits/stdc++.h>

int n, m, b;
constexpr int MAX = 501; // 501
int board[MAX][MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n >> m >> b;

    int min_height = INT_MAX;
    int max_height = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];

            min_height = std::min(min_height, board[i][j]);
            max_height = std::max(max_height, board[i][j]);
        }
    }

    int ans = INT_MAX;
    int ans2 = 0;
    for (int height = min_height; height <= max_height; ++height)
    {
        int add_blocks = 0;    // 1초 소요
        int remove_blocks = 0; // 2초 소요
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (height > board[i][j])
                {
                    add_blocks += height - board[i][j];
                }
                else if (height < board[i][j])
                {
                    remove_blocks += board[i][j] - height;
                }
            }
        }

        if (remove_blocks + b >= add_blocks)
        {
            int time = 2 * remove_blocks + add_blocks;
            if (ans > time)
            {
                ans = time;
                ans2 = height;
            }
            else if (ans == time)
            {
                ans2 = std::max(ans2, height);
            }
        }
    }

    std::cout << ans << " " << ans2;

    // int nn;
    // std::cin >> nn;
    return 0;
}