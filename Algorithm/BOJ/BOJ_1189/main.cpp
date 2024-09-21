
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int r, c, k;
int ans;

constexpr int MAX = 5;
char adj[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visit[MAX][MAX];

void dfs(int x, int y, int dist)
{
    // 오른쪽위에 도착하면 종료
    if (x == 0 && y == (c - 1))
    {
        if (dist == k)
        {
            ++ans;
        }
        return;
    }

    for (int d = 0; d < 4; ++d)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
        {
            continue;
        }

        if (visit[nx][ny])
        {
            continue;
        }

        if (adj[nx][ny] == 'T')
        {
            continue;
        }

        visit[nx][ny] = true;
        dfs(nx, ny, dist + 1);
        visit[nx][ny] = false;
    }
}

int main()
{
    FASTIO;
    std::cin >> r >> c >> k;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cin >> adj[i][j];
        }
    }

    // 왼쪽아래 시작 (r-1,0)
    // 오른쪽 위 도착 (0, c-1)
    visit[r - 1][0] = true; // <- 이거 놓쳐서 다풀어놓고 틀렸음..
    dfs(r - 1, 0, 1);

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}