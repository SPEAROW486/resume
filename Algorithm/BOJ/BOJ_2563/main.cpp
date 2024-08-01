
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
int board[MAX][MAX];
int n;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int left, bottom;
        std::cin >> left >> bottom;

        for (int i = left; i < left + 10; ++i)
        {
            for (int j = 100 - bottom - 10; j < 100 - bottom; ++j)
            {
                board[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (board[i][j] == 1)
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