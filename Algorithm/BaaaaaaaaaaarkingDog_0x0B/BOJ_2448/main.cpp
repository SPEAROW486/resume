
#include <bits/stdc++.h>

constexpr int MAX = 1024;
char board[3 * MAX + 1][6 * MAX + 1];

char tree[3][6] = {
    "  *  ",
    " * * ",
    "*****"};

void Solve(int x, int y, int n)
{
    // 여기 들어오면 n이 2^K 임.
    if (n == 1)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                board[x + i][y + j] = tree[i][j];
            }
        }
        return;
    }

    int half = n / 2;

    // 각 파티션의 좌상단 포인트
    Solve(x, y + 3 * half, half);
    Solve(x + 3 * half, y, half);
    Solve(x + 3 * half, y + 3 * n, half);
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::fill(&board[0][0], &board[3 * MAX][6 * MAX + 1], ' ');

    // n이 3 * 2^K 형태기때문에
    // 3을 나누고 재귀함수에선 2씩 나눠가면서 분할정복
    Solve(0, 0, n / 3);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2 * n - 1; ++j)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}