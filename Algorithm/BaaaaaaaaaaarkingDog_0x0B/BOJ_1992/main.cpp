
#include <bits/stdc++.h>

constexpr int MAX = 65;
char board[MAX][MAX];
std::string ans;

bool IsEqual(int x, int y, int n)
{
    for (int i = x; i < x + n; ++i)
    {
        for (int j = y; j < y + n; ++j)
        {
            if (board[i][j] != board[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

void Solve(int x, int y, int n)
{
    if (IsEqual(x, y, n))
    {
        ans += board[x][y];
        return;
    }

    int half = n / 2;
    // 4등분 한 각각의 색종이에도 다시 이걸 적용해야하니까..

    int dx[4] = {x, x, x + half, x + half};
    int dy[4] = {y, y + half, y, y + half};
    ans += "(";
    for (int i = 0; i < 4; ++i)
    {
        Solve(dx[i], dy[i], half);
    }
    ans += ")";

    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.length(); ++j)
        {
            board[i][j] = s[j];
        }
    }

    Solve(0, 0, n);

    std::cout << ans;

    return 0;
}