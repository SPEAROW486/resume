
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2210

char board[5][5];
std::unordered_set<std::string> set;
std::queue<std::tuple<int, int, std::string>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    FASTIO;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            q.push({i, j, std::string(1, board[i][j])});
            while (!q.empty())
            {
                int cx, cy;
                std::string str;
                std::tie(cx, cy, str) = q.front();
                q.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];

                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                    {
                        continue;
                    }

                    if (str.length() > 5)
                    {
                        set.insert(str);
                        continue;
                    }

                    q.push({nx, ny, str + board[nx][ny]});
                }
            }
        }
    }

    std::cout << set.size() << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}