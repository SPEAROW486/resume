
#include <bits/stdc++.h>

constexpr int MAX = 201;
constexpr int JUMP = 31;

// 말이냐 원숭이냐로 하는게 아니라 점프를 한 횟수로 버퍼를 나눠야..

int board[MAX][MAX];
int dist[MAX][MAX][JUMP];

int dx_monkey[4] = {-1, 1, 0, 0};
int dy_monkey[4] = {0, 0, -1, 1};

int dx_horse[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy_horse[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;

    int w, h;
    std::cin >> w >> h;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    // w == column h == row

    // cx,cy,jump
    std::queue<std::tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    // 벽 부수고 이동하기랑 비슷한 거 같음.
    // 내가 벽을 부수고 이동한 경로인지 아닌지를 검사하면서 넘어가야하니까 여기서는 그게 점프의 사용 횟수   ?? 제대로 적어놓고 왜 코드는 말이냐 원숭이로 했냐..
    // 방문 배열에 종류도 벽 부수기처럼 불값으로 2종류로 쓸수도있지만 인티저 값으로 나눠서 쓸수도있다는걸 생각해야했던 문제!
    while (!q.empty())
    {
        int cx, cy, jump;
        std::tie(cx, cy, jump) = q.front();
        q.pop();

        // 말
        if (jump < k)
        {
            for (int dir = 0; dir < 8; ++dir)
            {
                int nx = cx + dx_horse[dir];
                int ny = cy + dy_horse[dir];

                // 맵
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    continue;
                }

                // 장애물
                if (board[nx][ny] == 1)
                {
                    continue;
                }

                // 방문
                if (dist[nx][ny][jump + 1] > 0)
                {
                    continue;
                }

                dist[nx][ny][jump + 1] = dist[cx][cy][jump] + 1;
                q.push({nx, ny, jump + 1});
            }
        }

        // 원숭이
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cx + dx_monkey[dir];
            int ny = cy + dy_monkey[dir];

            // 맵
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            {
                continue;
            }

            // 장애물
            if (board[nx][ny] == 1)
            {
                continue;
            }

            // 방문
            if (dist[nx][ny][jump] > 0)
            {
                continue;
            }

            dist[nx][ny][jump] = dist[cx][cy][jump] + 1;
            q.push({nx, ny, jump});
        }
    }

    int min = std::numeric_limits<int>::max();
    int tx = h - 1;
    int ty = w - 1;
    for (int i = 0; i <= k; ++i)
    {
        if (dist[tx][ty][i] == 0)
        {
            continue;
        }
        min = std::min(min, dist[tx][ty][i]);
    }

    // 아무것도 방문하지 못하면 min이 기본값인데
    // 내가 기본값을 맥스로 잡아뒀으니 여기 조건문도 맥스로..
    if (min != std::numeric_limits<int>::max())
    {
        std::cout << min - 1;
    }
    else
    {
        std::cout << -1;
    }
    return 0;
}