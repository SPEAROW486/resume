
#include <bits/stdc++.h>

constexpr int MAX = 501; // 501;

int board[MAX][MAX];
bool visit[MAX][MAX];
int n, m;
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, int val)
{
    if (cnt == 4)
    {
        ans = std::max(ans, val);
        return;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= n || nx < 0 || ny >= m || ny < 0)
        {
            continue;
        }

        if (visit[nx][ny])
        {
            continue;
        }

        visit[nx][ny] = true;
        dfs(nx, ny, cnt + 1, val + board[nx][ny]);
        visit[nx][ny] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            visit[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visit[i][j] = false;
        }
    }

    // ㅗ 모양
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int min = INT_MAX;
            int sum = board[i][j];
            int add_count = 0;
            for (int k = 0; k < 4; ++k)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= n || nx < 0 || ny >= m || ny < 0)
                {
                    continue;
                }

                sum += board[nx][ny];
                min = std::min(min, board[nx][ny]);
                ++add_count;
            }

            sum = add_count == 4 ? sum - min : sum;
            ans = std::max(ans, sum);
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}