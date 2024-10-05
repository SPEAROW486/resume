#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 17129

int n, m;
std::vector<std::vector<char>> map;
std::vector<std::vector<int>> visited;
std::queue<std::pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int start_x, int start_y)
{
    q.push({start_x, start_y});
    visited[start_x][start_y] = 0;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        // 목표 위치(3, 4) 발견 시 거리 리턴
        if (map[x][y] > '2')
        {
            return visited[x][y];
        }

        // 현재 위치에서 네 방향으로 탐색
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵을 벗어나거나 벽이거나 이미 방문한 곳이면 패스
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '1' || visited[nx][ny])
            {
                continue;
            }

            // 방문 처리 후 큐에 삽입
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1; // 목표 위치에 도달할 수 없을 때
}

int main()
{
    FASTIO;

    std::cin >> n >> m;
    map.resize(n, std::vector<char>(m));
    visited.resize(n, std::vector<int>(m, 0));

    int start_x, start_y;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
            if (map[i][j] == '2')
            { // 시작 위치
                start_x = i;
                start_y = j;
            }
        }
    }

    int result = bfs(start_x, start_y);

    if (result == -1)
    {
        std::cout << "NIE" << '\n';
    }
    else
    {
        std::cout << "TAK" << '\n';
        std::cout << result << '\n';
    }

    return 0;
}
