
#include <bits/stdc++.h>

constexpr int MAX = 15;

int buf[MAX][MAX];

int main()
{

    int tc;
    std::cin >> tc;

    for (int i = 0; i < MAX; ++i)
    {
        buf[0][i] = i + 1;
        buf[i][0] = 1;
    }

    for (int i = 1; i < MAX; ++i)
    {
        for (int j = 1; j < MAX; ++j)
        {
            buf[i][j] = buf[i][j - 1] + buf[i - 1][j];
        }
    }

    while (tc--)
    {
        int k, n;
        std::cin >> k >> n;

        std::cout << buf[k][n - 1] << "\n";
    }

    return 0;
}