
#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 101;
constexpr int NO_TOMATO = -1;
constexpr int TOMATO = 0;
constexpr int RIPE_TOMATO = 1;

int board[MAX][MAX][MAX];
int vis[MAX][MAX][MAX];

int minimum_date = 0;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n, h;
    std::cin >> m >> n >> h;

    // 풀이의 큰 방향은 맞았는데 입력이 2차원, 3차원으로 들어올때 로우,컬럼 반대로 들어오는거때문에 엄청 헷갈리므로
    // 입력부터 제대로 받고 있는지 한번 제대로 생각하고 넘어가야할듯.

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                int temp;
                std::cin >> temp;
                board[j][k][i] = temp;

                if (temp == TOMATO)
                {
                    vis[j][k][i] = -1;
                }

                if (temp == RIPE_TOMATO)
                {
                    q.push({j, k, i});
                }
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int cx, cy, cz;
        tie(cx, cy, cz) = cur;
        for (int dir = 0; dir < 6; ++dir)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nz = cz + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
            {
                continue;
            }

            if (vis[nx][ny][nz] >= 0)
            {
                continue;
            }

            vis[nx][ny][nz] = vis[cx][cy][cz] + 1;
            q.push({nx, ny, nz});
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (vis[j][k][i] == -1)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                minimum_date = max(minimum_date, vis[j][k][i]);
            }
        }
    }
    std::cout << minimum_date;

    return 0;
}