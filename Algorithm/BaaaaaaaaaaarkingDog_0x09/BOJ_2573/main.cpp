
#include <bits/stdc++.h>

constexpr int MAX = 301;

int board[MAX][MAX];
int height[MAX][MAX];
bool vis[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m; // row, col
    std::cin >> n >> m;

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
            if (board[i][j] != 0)
            {
                q.push({i, j});
            }
        }
    }

    int years = 0;
    while (true)
    {
        ++years;
        std::copy(&board[0][0], &board[MAX - 1][MAX], &height[0][0]);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }

                if (board[nx][ny] != 0)
                {
                    continue;
                }

                if (height[cur.X][cur.Y] == 0)
                {
                    continue;
                }

                --height[cur.X][cur.Y];
            }
        }

        int count = 0;
        std::queue<std::pair<int, int>> q2;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (height[i][j] == 0)
                {
                    continue;
                }

                if (vis[i][j])
                {
                    continue;
                }

                vis[i][j] = true;
                q2.push({i, j});
                q.push({i, j});
                while (!q2.empty())
                {
                    auto cur = q2.front();
                    q2.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        {
                            continue;
                        }

                        if (height[nx][ny] == 0)
                        {
                            continue;
                        }

                        if (vis[nx][ny])
                        {
                            continue;
                        }

                        vis[nx][ny] = true;
                        q2.push({nx, ny});

                        // 빙산 녹이기용 큐에 다시 빙산의 위치를 푸쉬
                        q.push({nx, ny});
                    }
                }
                ++count;
            }
        }
        if (count == 0)
        {
            std::cout << 0;
            break;
        }
        else if (count > 1)
        {
            // 영역이 2개 이상으로 나온다면
            std::cout << years;
            break;
        }

        std::copy(&height[0][0], &height[MAX - 1][MAX], &board[0][0]);
        std::fill(&vis[0][0], &vis[MAX - 1][MAX], false);
    }

    return 0;
}