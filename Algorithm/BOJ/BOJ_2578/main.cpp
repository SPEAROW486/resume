
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 5;
int board[MAX][MAX];
bool marked[MAX][MAX];
int ans;

bool solve()
{
    int cnt = 0;
    for (int i = 0; i < 5; ++i)
    {
        bool bingo = true;
        for (int j = 0; j < 5; ++j)
        {
            if (!marked[i][j])
            {
                bingo = false;
                break;
            }
        }

        if (bingo)
        {
            ++cnt;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        bool bingo = true;
        for (int j = 0; j < 5; ++j)
        {
            if (!marked[j][i])
            {
                bingo = false;
                break;
            }
        }

        if (bingo)
        {
            ++cnt;
        }
    }

    bool diag1 = true;
    bool diag2 = true;
    for (int i = 0; i < 5; ++i)
    {
        if (!marked[i][i])
        {
            diag1 = false;
        }

        if (!marked[i][4 - i])
        {
            diag2 = false;
        }
    }

    if (diag1)
    {
        ++cnt;
    }
    if (diag2)
    {
        ++cnt;
    }

    return cnt >= 3;
}

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

    for (int i = 0; i < 25; ++i)
    {
        int tmp;
        std::cin >> tmp;

        // 해당하는 칸을 지우고
        // 빙고 체크 해야함.
        ++ans;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (board[i][j] == tmp)
                {
                    marked[i][j] = true;
                }
            }
        }

        if (solve())
        {
            std::cout << ans << "\n";
            break;
        }
    }
    return 0;
}