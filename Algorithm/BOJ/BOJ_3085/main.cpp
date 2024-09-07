
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

std::vector<std::vector<char>> board;

int get_max_length()
{
    int max_length = 1;

    // 가로
    for (int i = 0; i < n; ++i)
    {
        int cnt = 1;
        for (int j = 1; j < n; ++j)
        {
            if (board[i][j] == board[i][j - 1])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }

            if (cnt > max_length)
            {
                max_length = cnt;
            }
        }
    }

    // 세로
    for (int j = 0; j < n; ++j)
    {
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (board[i - 1][j] == board[i][j])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }

            if (cnt > max_length)
            {
                max_length = cnt;
            }
        }
    }

    return max_length;
}

int main()
{
    FASTIO;
    std::cin >> n;
    board.resize(n);

    for (int i = 0; i < n; ++i)
    {
        board[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            char tmp;
            std::cin >> tmp;
            board[i][j] = tmp;
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j + 1 < n)
            {
                std::swap(board[i][j], board[i][j + 1]);
                result = std::max(result, get_max_length());
                std::swap(board[i][j], board[i][j + 1]);
            }

            if (i + 1 < n)
            {
                std::swap(board[i][j], board[i + 1][j]);
                result = std::max(result, get_max_length());
                std::swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    std::cout << result << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}