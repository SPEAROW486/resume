
#include <bits/stdc++.h>

constexpr int MAX = 2188;
char board[MAX][MAX];

void Solve(int x, int y, int n)
{
    if (n == 1)
    {
        board[x][y] = '*';
        return;
    }

    int third = n / 3;

    int dx[8] = {x, x, x,
                 x + third, x + third,
                 x + third * 2, x + third * 2, x + third * 2};
    int dy[8] = {
        y,
        y + third,
        y + third * 2,
        y,
        y + third * 2,
        y,
        y + third,
        y + third * 2,
    };
    for (int i = 0; i < 8; ++i)
    {
        Solve(dx[i], dy[i], third);
    }

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::fill(&board[0][0], &board[MAX - 1][MAX], ' ');

    Solve(0, 0, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}