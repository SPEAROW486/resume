
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

constexpr int MAX = 101;

char board[MAX][MAX];
char board_cb[MAX][MAX];

bool vis[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;
int area_count = 0;

template <typename T>
void Dump(T *buf, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << buf[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void BFS(int x, int y)
{
    vis[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
            {
                continue;
            }

            if (vis[nx][ny] || board[cur.X][cur.Y] != board[nx][ny])
            {
                continue;
            }

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.length(); ++j)
        {
            board[i][j] = s[j];
            if (s[j] == 'G')
            {
                board_cb[i][j] = 'R';
            }
            else
            {
                board_cb[i][j] = s[j];
            }
        }
    }

    int tc = 2;
    while (tc--)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!vis[i][j])
                {
                    BFS(i, j);
                    ++area_count;
                }
            }
        }

        std::cout << area_count << " ";
        area_count = 0;
        std::fill(vis[0], vis[MAX - 1], false);
        memcpy(board, board_cb, sizeof(board_cb));
    }

    return 0;
}