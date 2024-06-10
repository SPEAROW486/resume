
#include <bits/stdc++.h>

int n, m;

std::string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"};

std::string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"};

constexpr int MAX = 50;
std::string board[50];

int func_wb(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i + x][j + y] != WB[i][j])
            {
                ++cnt;
            }
        }
    }
    return cnt;
}

int func_bw(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i + x][j + y] != BW[i][j])
            {
                ++cnt;
            }
        }
    }
    return cnt;
}

int main()
{
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> board[i];
    }

    int result = std::numeric_limits<int>::max();
    for (int i = 0; i <= n - 8; ++i)
    {
        for (int j = 0; j <= m - 8; ++j)
        {
            int min = std::min(func_bw(i, j), func_wb(i, j));
            result = std::min(min, result);
        }
    }

    std::cout << result;
    return 0;
}