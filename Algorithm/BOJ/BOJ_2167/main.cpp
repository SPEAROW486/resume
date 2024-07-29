
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 301;
int board[MAX][MAX];

int n, m;
int k;

int main()
{
    FASTIO;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    std::cin >> k;
    while (k--)
    {
        int si, sj, ei, ej;
        std::cin >> si >> sj >> ei >> ej;

        int sum = 0;
        for (int i = si - 1; i < ei; ++i)
        {
            for (int j = sj - 1; j < ej; ++j)
            {
                sum += board[i][j];
            }
        }

        std::cout << sum << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}