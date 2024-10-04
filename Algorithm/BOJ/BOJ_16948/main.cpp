#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 16948

struct Point
{
    int x, y;
};

int N;
std::vector<std::vector<int>> board;
std::vector<std::vector<int>> visited;

// 데스 나이트가 이동할 수 있는 방향 (총 6가지)
const std::vector<Point> directions = {
    {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

// 주어진 좌표가 보드 내에 있는지 확인
bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs(Point start, Point end)
{
    std::queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = 0;

    while (!q.empty())
    {
        Point current = q.front();
        q.pop();

        // 도착 지점에 도달하면 이동 횟수를 반환
        if (current.x == end.x && current.y == end.y)
        {
            return visited[current.x][current.y];
        }

        // 6가지 방향으로 이동
        for (const auto &dir : directions)
        {
            int nx = current.x + dir.x;
            int ny = current.y + dir.y;

            if (isValid(nx, ny) && visited[nx][ny] == -1)
            {
                visited[nx][ny] = visited[current.x][current.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 도착할 수 없을 경우 -1 반환
    return -1;
}

int main()
{
    FASTIO;

    std::cin >> N;

    Point start, end;
    std::cin >> start.x >> start.y >> end.x >> end.y;

    board = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    visited = std::vector<std::vector<int>>(N, std::vector<int>(N, -1));

    int result = bfs(start, end);

    std::cout << result << "\n";

    return 0;
}
