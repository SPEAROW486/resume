
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 13565
// BFS?
// 위쪽에서 침투해서 아래쪽까지 닿을수있는가?

// 위쪽은 0행을 말하는거고 아래쪽은 m-1행을 말하는거인가?
// 0이 흰색
// 가장 바깥쪽 0번 격자에서 침투 가능
// BFS로 플러드필 하고 m-1번 행만 검사해서 한 칸이라도 방문했으면 침투인가?

constexpr int MAX = 1001;

int m, n; // m -> row , n -> col

int adj[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    FASTIO;

    std::cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        std::string str;
        std::cin >> str;

        for (int j = 0; j < str.length(); ++j)
        {
            adj[i][j] = str[j] - '0';
        }
    }

    std::queue<std::pair<int, int>> q;

    for (int j = 0; j < n; ++j)
    {
        if (visit[0][j])
        {
            continue;
        }

        if (adj[0][j] != 0)
        {
            continue;
        }

        q.push({0, j});
        visit[0][j] = true;

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

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                {
                    continue;
                }

                if (visit[nx][ny])
                {
                    continue;
                }

                if (adj[nx][ny] != 0)
                {
                    continue;
                }

                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }

    bool ans = false;
    for (int j = 0; j < n; ++j)
    {
        if (visit[m - 1][j])
        {
            ans = true;
            break;
        }
    }

    std::string str = ans ? "YES" : "NO";
    std::cout << str << "\n";

    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         std::cout << visit[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    // int nn;
    // std::cin >> nn;
    return 0;
}