
#include <bits/stdc++.h>

constexpr int MAX = 601;

char board[MAX][MAX];
int vis[MAX][MAX];
int n, m;

constexpr char BLANK = 'O';
constexpr char WALL = 'X';
constexpr char DOYEON = 'I';
constexpr char PERSON = 'P';

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
        {
            board[i][j] = s[j];
            if (board[i][j] == DOYEON)
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int meet = 0;
    while (!q.empty())
    {
        const auto front = q.front();
        q.pop();

        if (board[front.X][front.Y] == PERSON)
        {
            ++meet;
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = front.X + dx[dir];
            int ny = front.Y + dy[dir];

            if (nx >= n || nx < 0 || ny >= m || ny < 0)
            {
                continue;
            }

            if (board[nx][ny] == WALL)
            {
                continue;
            }

            if (vis[nx][ny])
            {
                continue;
            }

            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }

    std::string result = meet != 0 ? std::to_string(meet) : "TT";
    std::cout << result;

    // int nn;
    // std::cin >> nn;
    return 0;
}