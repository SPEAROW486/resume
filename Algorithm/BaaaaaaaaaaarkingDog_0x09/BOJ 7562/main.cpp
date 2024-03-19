
#include <bits/stdc++.h>

constexpr int MAX = 301;
int board[MAX][MAX];
int dist[MAX][MAX];
int minimum_movement_count = 0;

// 대략 8시 방향부터 시계 방향으로 탐색
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 여기선 입력이 무조건 l & l 이니까 가로 세로 헷갈리지 않을듯.

    // 1번째 입력 -> TC의 개수 -> TC
    // 2번째 입력 -> 체스판의 한변의 길이 -> L
    // 3번쨰 입력 -> 나이트의 현재 위치 -> s
    // 4번째 입력 -> 나이트가 이동하려고 하는 위치 t

    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int l;
        std::cin >> l;

        int sx, sy;
        std::cin >> sx >> sy;
        int tx, ty;
        std::cin >> tx >> ty;

        // 시작위치랑 현재 위치가 같으면 0출력하고 건너뛰기.
        if (sx == tx && sy == ty)
        {
            std::cout << 0 << "\n";
            continue;
        }
        // 그게아니면 현재 위치를 큐에 푸쉬
        std::queue<std::pair<int, int>> q;
        q.push({sx, sy});
        // dist[sx][sy] = 0; 전역배열이라 기본 0으로 초기화 되있으니 굳이 필요없을듯?

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; ++dir)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                {
                    continue;
                }

                if (dist[nx][ny] > 0)
                {
                    continue;
                }

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                minimum_movement_count = std::max(minimum_movement_count, dist[nx][ny]);
                q.push({nx, ny});

                if (nx == tx && ny == ty)
                {
                    q = std::queue<std::pair<int, int>>();
                    break;
                }
            }
        }

        std::cout << minimum_movement_count << "\n";
        std::fill(board[0], board[MAX - 1], 0);
        std::fill(dist[0], dist[MAX - 1], 0);
        minimum_movement_count = 0;
    }
    return 0;
}