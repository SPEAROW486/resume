
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
bool board[MAX][MAX];

int main()
{
    FASTIO;
    int tmp = 4;
    while (tmp--)
    {
        int y1, x1, y2, x2;
        std::cin >> y1 >> x1 >> y2 >> x2;
        for (int i = x1; i < x2; ++i)
        {
            for (int j = y1; j < y2; ++j)
            {
                board[i][j] = true;
            }
        }
    }

    std::cout << std::count(&board[0][0], &board[MAX - 1][MAX], true);

    // int nn;
    // std::cin >> nn;
    return 0;
}