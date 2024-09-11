
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 11123
// 2차원 BFS, flood_fill 

constexpr int MAX = 10001;
int n;
std::vector<int> v;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int flood_fill(int h, int w, const std::vector<std::string> &adj)
{
    bool visit[h][w];
    memset(visit, false, sizeof(visit));

    int cnt = 0;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (visit[i][j])
            {
                continue;
            }

            if (adj[i][j] == '.')
            {
                continue;
            }

            q.push({i, j});
            visit[i][j] = true;

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

                    if (nx < 0 || nx >= h || ny < 0 || ny >= w)
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
                }
            }
            ++cnt;
        }
    }

    return cnt;
}

int main()
{
    FASTIO;
    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int h, w;
        std::cin >> h >> w;
        std::vector<std::string> adj;

        for (int i = 0; i < h; ++i)
        {
            std::string tmp;
            std::cin >> tmp;
            adj.push_back(tmp);
        }

        std::cout << flood_fill(h, w, adj) << "\n";
    }

    return 0;
}
