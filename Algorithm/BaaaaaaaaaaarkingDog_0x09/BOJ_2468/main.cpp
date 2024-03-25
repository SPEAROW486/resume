
#include <bits/stdc++.h>

constexpr int MAX = 101;
int dist[MAX][MAX];
bool vis[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int max = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> dist[i][j];
            max = std::max(max, dist[i][j]);
        }
    }

    int maxcnt = std::numeric_limits<int>::min();
    for (int r = 0; r <= max; ++r)
    {
        int count = 0;
        // end는 마지막 요소의 다음 주소를 가르켜야함
        // ex) max = 10
        // 0,0 ~ 9,10 (9,9까지가 요소가 있는공간이니) 마지막 요소의 다음주소인 9,10을 가르켜야한다.
        std::fill(&vis[0][0], &vis[MAX - 1][MAX], false);
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j] <= r)
                {
                    continue;
                }

                if (vis[i][j])
                {
                    continue;
                }

                q.push({i, j});
                vis[i][j] = true;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        {
                            continue;
                        }

                        if (dist[nx][ny] <= r)
                        {
                            continue;
                        }

                        if (vis[nx][ny])
                        {
                            continue;
                        }

                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                ++count;
            }
        }
        maxcnt = std::max(count, maxcnt);
    }
    std::cout << maxcnt;

    return 0;
}