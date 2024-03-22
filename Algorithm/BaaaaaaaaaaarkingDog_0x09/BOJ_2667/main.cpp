
#include <bits/stdc++.h>

constexpr int MAX = 26;
int board[MAX][MAX];
bool vis[MAX][MAX];

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string nn;
        std::cin >> nn;
        for (int j = 0; j < n; ++j)
        {
            board[i][j] = nn[j] - 48;
        }
    }

    // 0 -> 집이 없음
    // 1 -> 집이 있음.

    std::queue<std::pair<int, int>> q;

    int complex_count = 0;
    std::vector<int> home_counts;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // 0이면 집이 없는거고 1이면 집이 있는데, 방문 여부도 검사해야함.
            // 숫자 배열이라 다른 값을 플래그로 써도되는데 헷갈릴수 있으니 방문버퍼를 하나 쓰는거로
            if (board[i][j] == 0)
            {
                continue;
            }

            if (vis[i][j])
            {
                continue;
            }

            q.push({i, j});
            vis[i][j] = true;
            ++complex_count;

            int home = 1;
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    {
                        continue;
                    }

                    if (board[nx][ny] == 0)
                    {
                        continue;
                    }

                    if (vis[nx][ny])
                    {
                        continue;
                    }

                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    ++home;
                }
            }
            home_counts.push_back(home);
        }
    }

    std::sort(home_counts.begin(), home_counts.end());

    std::cout << complex_count << "\n";
    for (const int c : home_counts)
    {
        std::cout << c << "\n";
    }

    return 0;
}