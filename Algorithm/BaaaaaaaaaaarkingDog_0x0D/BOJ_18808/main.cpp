
#include <bits/stdc++.h>

constexpr int MAX = 40;
int n, m, k;

int board[MAX][MAX];
int sticker[MAX][MAX];

void Dump()
{
    std::cout << "\n";
    std::cout << "\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool OOB(int, int);

bool TryAttach(int x, int y, size_t sx, size_t sy)
{
    // x, y = 현재 붙히려고 시도할 위치
    // sx, sy = 스티커의 사이즈
    bool result = true;
    int cpy_board[MAX][MAX];
    memcpy(cpy_board, board, sizeof(board));
    for (int i = 0; i < sx; ++i)
    {
        for (int j = 0; j < sy; ++j)
        {
            int nx = i + x;
            int ny = j + y;
            if (OOB(nx, ny))
            {
                return false;
            }

            if (sticker[i][j] == 0)
            {
                continue;
            }

            cpy_board[nx][ny] = sticker[i][j];
            result &= board[nx][ny] == 0;
        }
    }

    if (result)
    {
        std::memmove(board, cpy_board, sizeof(cpy_board));
        return true;
    }
    return false;
}

bool OOB(int a, int b)
{
    return a < 0 || a >= n || b < 0 || b >= m;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;

    while (k--)
    {
        std::fill(&sticker[0][0], &sticker[MAX - 1][MAX], 0);
        int x, y;
        std::cin >> x >> y;
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                std::cin >> sticker[i][j];
            }
        }

        size_t sx = x;
        size_t sy = y;
        bool Attach = false;
        for (int dir = 0; dir < 4 && !Attach; ++dir)
        {
            if (dir != 0)
            {
                int temp[MAX][MAX];
                for (int i = 0; i < sx; ++i)
                {
                    for (int j = 0; j < sy; ++j)
                    {
                        temp[j][sx - 1 - i] = sticker[i][j];
                    }
                }
                std::memmove(sticker, temp, sizeof(temp));
                std::swap(sx, sy);
            }

            for (int i = 0; i < MAX && !Attach; ++i)
            {
                for (int j = 0; j < MAX; ++j)
                {
                    Attach = TryAttach(i, j, sx, sy);
                    if (Attach)
                    {
                        break;
                    }
                }
            }
        }
    }

    std::cout << std::count(&board[0][0], &board[MAX - 1][MAX], 1);

    return 0;
}