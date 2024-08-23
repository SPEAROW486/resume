
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MAX = 4;
int board[MAX][MAX];
bool visit[MAX][MAX];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int main()
{
    // FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = true;

    bool arrive = false;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == n - 1 && cy == n - 1)
        {
            arrive = true;
            break;
        }

        int amount = board[cx][cy];
        for (int dir = 0; dir < 2; ++dir)
        {
            int nx = cx + (dx[dir] * amount);
            int ny = cy + (dy[dir] * amount);

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }

            if (visit[nx][ny])
            {
                continue;
            }

            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }

    if (arrive)
    {
        std::cout << "HaruHaru\n";
    }
    else
    {
        std::cout << "Hing\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}