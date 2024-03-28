
#include <bits/stdc++.h>

constexpr int MAX = 101;

int board[MAX][MAX];
int vis[MAX][MAX];  // 섬의 번호로 방문 여부를 검사
int dist[MAX][MAX]; // 방문 여부 검사와 별도로 거리로 채울 배열

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

constexpr int VISITED = 1;

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    // 섬 번호 매기기, 엣지 파악하기
    int number = 0;
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 0)
            {
                continue;
            }

            if (vis[i][j] == VISITED)
            {
                continue;
            }

            ++number;
            vis[i][j] = VISITED;
            board[i][j] = number;
            q.push({i, j});
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

                    if (vis[nx][ny] == VISITED)
                    {
                        continue;
                    }

                    if (board[nx][ny] == 0)
                    {
                        edges.insert({cur.X, cur.Y});
                        continue;
                    }

                    board[nx][ny] = number;
                    vis[nx][ny] = VISITED;
                    q.push({nx, ny});
                }
            }
        }
    }

    // 엣지부터 시작해서 다른 섬 찾을때가찌 BFS
    int shortest_path = std::numeric_limits<int>::max();
    std::queue<std::pair<int, int>> q2;
    for (auto edge : edges)
    {
        int edge_x = edge.X;
        int edge_y = edge.Y;
        int current_island = board[edge_x][edge_y];
        q2.push({edge_x, edge_y});

        while (!q2.empty())
        {
            auto cur = q2.front();
            q2.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                {
                    continue;
                }

                if (dist[nx][ny] != 0)
                {
                    continue;
                }

                // 바다가 아닌데
                if (board[nx][ny] != 0)
                {
                    if (board[nx][ny] != current_island)
                    {
                        // 다른 섬이면
                        shortest_path = std::min(shortest_path, dist[cur.X][cur.Y]);
                        continue;
                    }
                    else
                    {
                        // 같은 섬이면
                        continue;
                    }
                }

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q2.push({nx, ny});
            }
        }

        // 788ms 걸렸음
        // 버퍼를 초기화 시키는 코드를 너무 안쓰려고 하지 않아도 될듯..
        // 필요하면 초기화 하는거지
        std::fill(&dist[0][0], &dist[MAX - 1][MAX], 0);
    }
    std::cout << shortest_path;
    return 0;
}