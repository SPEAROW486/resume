
#include <bits/stdc++.h>

constexpr int MAX = 1001;
int n, m;
int visit[MAX][MAX];
int board[MAX][MAX];

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n >> m;

    std::queue<std::pair<int, int>> q;

    std::fill(&visit[0][0], &visit[MAX - 1][MAX], -1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 2)
            {
                q.push({i, j});
            }

            if (board[i][j] == 2 || board[i][j] == 0)
            {
                visit[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        const std::pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = front.X + dx[i];
            int ny = front.Y + dy[i];

            if (nx >= n || nx < 0 || ny >= m || ny < 0)
            {
                continue;
            }

            if (board[nx][ny] != 1)
            {
                continue;
            }

            if (visit[nx][ny] != -1)
            {
                continue;
            }

            visit[nx][ny] = visit[front.X][front.Y] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << visit[i][j] << " ";
        }
        std::cout << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}