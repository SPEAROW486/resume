
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

std::vector<std::string> mines;
std::vector<std::string> board;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool solve()
{
    bool ret = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] != 'x')
            {
                continue;
            }

            if (mines[i][j] == '*')
            {
                ret = false;
                continue;
            }

            int count = 0;
            for (int dir = 0; dir < 8; ++dir)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                {
                    continue;
                }

                if (mines[nx][ny] == '*')
                {
                    ++count;
                }
            }

            board[i][j] = count + '0';
        }
    }

    return ret;
}

int main()
{
    // FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        mines.push_back(tmp);
    }

    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        board.push_back(tmp);
    }

    if (!solve())
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mines[i][j] == '*')
                {
                    board[i][j] = '*';
                }
            }
        }
    }

    for (int i = 0; i < board.size(); ++i)
    {
        std::cout << board[i] << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}