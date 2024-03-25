
#include <bits/stdc++.h>

constexpr int MAX = 31;
char building[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    while (true)
    {
        int l, r, c;
        std::cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0)
        {
            break;
        }

        // l -> 층수
        // r -> row
        // c -> col
        std::fill(&dist[0][0][0], &dist[MAX - 1][MAX - 1][MAX], -1);

        std::queue<std::tuple<int, int, int>> q;

        int ex = 0;
        int ey = 0;
        int ez = 0;
        for (int length = 0; length < l; ++length)
        {
            for (int row = 0; row < r; ++row)
            {
                std::string s;
                std::cin >> s;
                for (int col = 0; col < c; ++col)
                {
                    building[row][col][length] = s[col];

                    if (s[col] == 'S')
                    {
                        q.push({row, col, length});
                        dist[row][col][length] = 0;
                    }

                    if (s[col] == 'E')
                    {
                        ex = row;
                        ey = col;
                        ez = length;
                    }
                }
            }
        }

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int curX, curY, curZ;
            std::tie(curX, curY, curZ) = cur;

            for (int dir = 0; dir < 6; ++dir)
            {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
                {
                    continue;
                }

                if (dist[nx][ny][nz] != -1)
                {
                    continue;
                }

                if (building[nx][ny][nz] != '#')
                {
                    q.push({nx, ny, nz});
                    dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                }
            }
        }

        if (dist[ex][ey][ez] != -1)
        {
            std::cout << "Escaped in " << dist[ex][ey][ez] << " minute(s).\n";
        }
        else
        {
            std::cout << "Trapped!\n";
        }
    }
    return 0;
}