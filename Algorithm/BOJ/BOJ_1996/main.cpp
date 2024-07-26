
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001;
int n;
std::string map[MAX];
int ans[MAX][MAX];

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dump()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char c;
            if (ans[i][j] == -1)
            {
                c = '*';
            }
            else if (ans[i][j] >= 10)
            {
                c = 'M';
            }
            else
            {
                // itoa(ans[i][j], &c, 10);
                c = ans[i][j] + '0';
            }
            std::cout << c;
        }
        std::cout << "\n";
    }
}

std::vector<std::pair<int, int>> mines;
void solve()
{
    for (const std::pair<int, int> &m : mines)
    {
        // 각 지뢰별로 8방향 돌면서 더해주면될듯
        for (int dir = 0; dir < 8; ++dir)
        {
            int nx = m.first + dx[dir];
            int ny = m.second + dy[dir];

            // OOB
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }

            // 지뢰가 매설된 곳
            if (ans[nx][ny] == -1)
            {
                continue;
            }

            ans[nx][ny] += map[m.first][m.second] - '0';
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> map[i];
        for (int j = 0; j < map[i].length(); ++j)
        {
            if (map[i][j] != '.')
            {
                ans[i][j] = -1;
                mines.push_back({i, j});
            }
        }
    }

    solve();
    dump();

    // int nn;
    // std::cin >> nn;
    return 0;
}