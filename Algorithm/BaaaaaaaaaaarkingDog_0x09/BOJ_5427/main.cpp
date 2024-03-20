
#include <bits/stdc++.h>

constexpr int MAX = 1001;
std::string board[MAX];
int dist_fire[MAX][MAX];
int dist_human[MAX][MAX];

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int w, h;
        std::cin >> w >> h;

        std::fill(dist_fire[0], dist_fire[MAX - 1], -1);
        std::fill(dist_human[0], dist_human[MAX - 1], -1);

        for (int i = 0; i < h; ++i)
        {
            std::string s;
            std::cin >> s;
            board[i] = s;
        }

        std::queue<std::pair<int, int>> q_fire;
        std::queue<std::pair<int, int>> q_human;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (board[i][j] == '*')
                {
                    q_fire.push({i, j});
                    dist_fire[i][j] = 0;
                }

                if (board[i][j] == '@')
                {
                    q_human.push({i, j});
                    dist_human[i][j] = 0;
                }
            }
        }

        while (!q_fire.empty())
        {
            auto cur = q_fire.front();
            q_fire.pop();
            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    continue;
                }

                if (board[nx][ny] == '#')
                {
                    continue;
                }

                if (dist_fire[nx][ny] >= 0)
                {
                    continue;
                }

                dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
                q_fire.push({nx, ny});
            }
        }

        bool escape = false;
        while (!q_human.empty() && !escape)
        {
            auto cur = q_human.front();
            q_human.pop();
            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    escape = true;
                    std::cout << dist_human[cur.X][cur.Y] + 1 << "\n";
                    break;
                }

                if (board[nx][ny] != '.' || dist_human[nx][ny] >= 0)
                {
                    continue;
                }

                // 여기서 너무 오래걸렸음.
                // 입력 예제만 보고 생각하지말고 버퍼값이 초기값일때도 생각을 해봐야함.
                if (dist_fire[nx][ny] == -1 || dist_fire[nx][ny] > dist_human[cur.X][cur.Y] + 1)
                {
                    q_human.push({nx, ny});
                    dist_human[nx][ny] = dist_human[cur.X][cur.Y] + 1;
                }
            }
        }

        if (!escape)
        {
            std::cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}