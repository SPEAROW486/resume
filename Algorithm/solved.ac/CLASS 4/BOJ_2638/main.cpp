
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101; // 101;
int n, m, c, ans;

int board[MAX][MAX];
bool visit[MAX][MAX];
int edges[MAX][MAX];

std::queue<std::pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs()
{
    // 맨 가장자리는 치즈가 없다는게 힌트였음.
    // 공기부터 시작해서 공기만 방문하고 치즈면 엣지 개수만 파악하는거라 내부공간 처리할 필요가 없음.

    q.push({0, 0});
    visit[0][0] = true;

    while (!q.empty())
    {
        const std::pair<int, int> front = q.front();
        q.pop();
        const int cur_x = front.first;
        const int cur_y = front.second;

        for (int dir = 0; dir < 4; ++dir)
        {
            const int nx = front.first + dx[dir];
            const int ny = front.second + dy[dir];

            if (nx >= n || nx < 0 || ny >= m || ny < 0)
            {
                continue;
            }

            if (visit[nx][ny])
            {
                continue;
            }

            if (board[nx][ny] == 0)
            {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
            else if (board[nx][ny] == 1)
            {
                ++edges[nx][ny];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (edges[i][j] >= 2)
            {
                board[i][j] = 0;
                --c;
            }
        }
    }

    memset(edges, 0, sizeof(edges));
    memset(visit, 0, sizeof(visit));
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 1)
            {
                ++c;
            }
        }
    }

    while (c != 0)
    {
        bfs();
        ++ans;
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}