#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 17086

constexpr int MAX = 51;
int n, m;

int adj[MAX][MAX];
int dist[MAX][MAX];

// 8방향을 나타내는 dx, dy 배열
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main()
{
    FASTIO;
    std::queue<std::pair<int, int>> q;

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> adj[i][j];

            if (adj[i][j] == 1)
            {
                q.push({i, j});
                // 아기상어 위치는 0로 초기화
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INT_MAX;
            }
        }
    }

    int max = 0;
    while (!q.empty())
    {
        std::pair<int, int> front = q.front();
        q.pop();

        int cx = front.first;
        int cy = front.second;

        for (int d = 0; d < 8; ++d)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (adj[nx][ny] == 1)
            {
                continue;
            }

            int distance = dist[cx][cy] + 1;
            if (dist[nx][ny] == INT_MAX)
            {
                dist[nx][ny] = distance;
                q.push({nx, ny});
                max = std::max(max, distance);
            }
            else if (dist[nx][ny] > distance)
            {
                dist[nx][ny] = distance;
                q.push({nx, ny});
                max = std::max(max, distance);
            }
        }
    }

    std::cout << max << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}
