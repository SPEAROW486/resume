
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MAX = 1001; // 1001;
char board[MAX][MAX];

int main()
{
    // FASTIO;
    std::cin >> n;
    bool heart = false;
    int hx = 0;
    int hy = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> board[i][j];

            if (board[i][j] == '*' && !heart)
            {
                hx = i + 1;
                hy = j;
                heart = true;
            }
        }
    }

    // 왼쪽 팔
    int leftarm = 0;
    for (int y = hy - 1; y >= 0; --y)
    {
        if (board[hx][y] == '*')
        {
            ++leftarm;
        }
    }

    // 오른 팔
    int rightarm = 0;
    for (int y = hy + 1; y < n; ++y)
    {
        if (board[hx][y] == '*')
        {
            ++rightarm;
        }
    }

    // 허리
    int spine = 0;
    int sx = 0;
    int sy = 0;
    for (int x = hx + 1; x < n; ++x)
    {
        if (board[x][hy] == '*')
        {
            ++spine;
            sx = x;
            sy = hy;
        }
    }

    // 왼쪽 다리
    int leftleg = 0;
    for (int x = sx + 1; x < n; ++x)
    {
        if (board[x][sy - 1] == '*')
        {
            ++leftleg;
        }
    }

    // 오른 다리
    int rightleg = 0;
    for (int x = sx + 1; x < n; ++x)
    {
        if (board[x][sy + 1] == '*')
        {
            ++rightleg;
        }
    }
    // 1부터 인덱스가 시작임 문제에서
    std::cout << hx + 1 << " " << hy + 1 << "\n";
    std::cout << leftarm << " " << rightarm << " " << spine << " " << leftleg << " " << rightleg << " ";

    int nn;
    std::cin >> nn;
    return 0;
}