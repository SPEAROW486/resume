#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14716

// 방향 벡터 설정 (상, 하, 좌, 우, 대각선 4방향)
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int n, m;
std::vector<std::vector<int>> banner;
std::vector<std::vector<bool>> visited;

// BFS로 연결된 1을 모두 방문
void bfs(int x, int y)
{
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        std::pair<int, int> front = q.front();
        q.pop();

        // 8방향 탐색
        for (int i = 0; i < 8; ++i)
        {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];

            // 유효한 범위 내에 있고, 아직 방문하지 않았으며, 값이 1인 경우에만 탐색
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && banner[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    FASTIO;

    std::cin >> n >> m;

    banner.resize(n, std::vector<int>(m));
    visited.resize(n, std::vector<bool>(m, false));

    // 현수막 입력
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> banner[i][j];
        }
    }

    int count = 0;

    // 모든 위치에 대해 BFS 실행하여 연결된 글자(1)의 그룹을 찾음
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (banner[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j);
                count++;
            }
        }
    }

    std::cout << count << '\n';
    return 0;
}
