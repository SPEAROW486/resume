
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
bool board[MAX][MAX];
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
            for (int j = bottom; j < bottom + 10; ++j)
            {
                board[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (board[i][j])
            {
                if (i == 0 || !board[i - 1][j])
                {
                    ++ans;
                }

                if (i == 99 || !board[i + 1][j])
                {
                    ++ans;
                }

                if (j == 0 || !board[i][j - 1])
                {
                    ++ans;
                }

                if (j == 99 || !board[i][j + 1])
                {
                    ++ans;
                }
            }
        }
    }

    std::cout << ans;
    return 0;
}