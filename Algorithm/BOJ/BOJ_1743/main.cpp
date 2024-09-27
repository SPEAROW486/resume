
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
int n, m, k;

char adj[MAX][MAX];
bool visit[MAX][MAX];
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y)
{
    if (visit[x][y])
    {
        return;
    }

    if (adj[x][y] == '.')
    {
        return;
    }

    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    int area = 1;
    while (!q.empty())
    {
        std::pair<int, int> front = q.front();
        q.pop();

        int cx = front.first;
        int cy = front.second;

        for (int d = 0; d < 4; ++d)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (visit[nx][ny])
            {
                continue;
            }

            if (adj[nx][ny] == '.')
            {
                continue;
            }

            q.push({nx, ny});
            visit[nx][ny] = true;
            ++area;
        }
    }

    ans = std::max(ans, area);
}

int main()
{
    FASTIO;

    std::cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            adj[i][j] = '.';
        }
    }

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1][y - 1] = '#';
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bfs(i, j);
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}