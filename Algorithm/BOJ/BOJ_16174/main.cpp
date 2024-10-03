#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 16174

int n;
std::vector<std::vector<int>> board;
std::vector<std::vector<bool>> visited;

// BFS를 이용하여 점프 가능한 경로 탐색
bool bfs()
{
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        std::pair<int, int> front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();

        int jump = board[x][y];

        // 목적지에 도달한 경우
        if (x == n - 1 && y == n - 1)
        {
            return true;
        }

        // 현재 위치에서 점프할 수 없을 때
        if (jump == 0)
        {
            continue;
        }

        // 오른쪽으로 점프
        int nx = x;
        int ny = y + jump;
        if (ny < n && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }

        // 아래로 점프
        nx = x + jump;
        ny = y;
        if (nx < n && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

int main()
{
    FASTIO;

    std::cin >> n;

    board.resize(n, std::vector<int>(n));
    visited.resize(n, std::vector<bool>(n, false));

    // 보드 입력
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    // BFS로 탐색하여 결과 출력
    if (bfs())
    {
        std::cout << "HaruHaru\n";
    }
    else
    {
        std::cout << "Hing\n";
    }

    return 0;
}
