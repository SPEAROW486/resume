#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 4963
// BFS?

int main()
{
    FASTIO;

    int w, h;
    while (true)
    {
        std::cin >> w >> h;

        if (w == 0 && h == 0)
        {
            break;
        }

        std::vector<std::vector<int>> v(h);

        for (int i = 0; i < h; ++i)
        {
            v[i].resize(w);
            for (int j = 0; j < w; ++j)
            {
                std::cin >> v[i][j];
            }
        }

        // bfs
        static int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

        bool visit[h][w];
        std::memset(visit, false, sizeof(visit));

        std::queue<std::pair<int, int>> q;

        int land = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (v[i][j] == 0)
                {
                    continue;
                }

                if (visit[i][j])
                {
                    continue;
                }

                q.push({i, j});
                visit[i][j] = true;

                while (!q.empty())
                {
                    int cx = q.front().first;
                    int cy = q.front().second;

                    q.pop();

                    for (int d = 0; d < 8; ++d)
                    {
                        int nx = cx + dx[d];
                        int ny = cy + dy[d];

                        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                        {
                            continue;
                        }

                        if (visit[nx][ny])
                        {
                            continue;
                        }

                        if (v[nx][ny] == 0)
                        {
                            continue;
                        }

                        q.push({nx, ny});
                        visit[nx][ny] = true;
                    }
                }

                ++land;
            }
        }

        std::cout << land << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
