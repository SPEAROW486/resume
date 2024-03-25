
#include <bits/stdc++.h>

constexpr int MAX = 1001;
int board[MAX][MAX];
bool vis[MAX][MAX][2];
int n, m;

constexpr int BLANK = 0;
constexpr int WALL = 1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define X first
#define Y second

int BFS()
{
    std::queue<std::tuple<int, int, bool, int>> q; // x,y, broken, dist

    // 벽을 부쉈냐 안부쉈냐 같은로직은 아까 내 로직도 되지만,
    // 방문 버퍼를 하나만 쓰기 때문에
    // 아직 벽을안부수고 지나온 경로도, 이전 탐색에서 벽을 부순 값이 있어서 오작동한거네..
    // n가지 경로를 탐색해야할 경우에는 그림을 좀 그려봐야 할듯.

    q.push({0, 0, 0, 1}); // 시작점은 0,0으로 고정, 벽이 없고 시작점도 거리에 포함해야하는 문제
    vis[0][0][0] = true;  // 0,0, 안부순곳 방문처리.

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int curX, curY, is_broken, dist;
        std::tie(curX, curY, is_broken, dist) = cur;

        if (curX == n - 1 && curY == m - 1)
        {
            return dist;
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (vis[nx][ny][is_broken])
            {
                // 내가 여기서 방문 검증 버퍼를 한개만 썼기 때문에 아직 안가본 경로도 이전 탐색에서 방문처리를 해서 건너뛰어버렸음.
                continue;
            }

            if (board[nx][ny] == WALL)
            {
                if (!is_broken)
                {
                    // 벽을 부수고온 경로가 아니라면 벽을 부순다.
                    vis[nx][ny][1] = true;
                    q.push({nx, ny, true, dist + 1});
                }
            }
            else
            {
                // 벽이 아니면 지금 지나온 경로를 저장해줘야함.
                vis[nx][ny][is_broken] = true;
                q.push({nx, ny, is_broken, dist + 1});
            }
        }
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
        {
            board[i][j] = s[j] - 48;
        }
    }

    std::cout << BFS();
    return 0;
}