
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--)
    {
        int m, n, k;
        std::cin >> m >> n >> k;

        int cabbages[51][51];
        bool vis[51][51];

        std::fill(cabbages[0], cabbages[50], 0);
        std::fill(vis[0], vis[50], false);

        int x, y;
        for (int j = 0; j < k; ++j)
        {
            std::cin >> x >> y;
            cabbages[y][x] = 1;
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (cabbages[i][j] == 1 && !vis[i][j])
                {
                    vis[i][j] = true;
                    q.push(pair<int, int>(i, j));

                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            pair<int, int> next(cur.X + dx[dir], cur.Y + dy[dir]);
                            if (next.X < 0 || next.X >= n || next.Y < 0 || next.Y >= m)
                            {
                                continue;
                            }

                            if (cabbages[next.X][next.Y] != 1 || vis[next.X][next.Y])
                            {
                                continue;
                            }

                            vis[next.X][next.Y] = true;
                            q.push(next);
                        }
                    }
                    ++count;
                }
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}