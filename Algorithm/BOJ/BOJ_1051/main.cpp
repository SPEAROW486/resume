
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 51;

char board[MAX][MAX];
int n, m;
int ans;

void tmp()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {

            for (int k = 0; k < n; ++k)
            {
                int nx = i + k;
                int ny = j + k;

                if (nx >= n || nx < 0 || ny >= m || ny < 0)
                {
                    continue;
                }

                if (board[i][j] == board[nx][j] && board[i][j] == board[i][ny] && board[i][j] == board[nx][ny])
                {
                    ans = std::max(ans, (k + 1) * (k + 1));
                }
            }
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
        {
            board[i][j] = s[j];
        }
    }

    tmp();

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}