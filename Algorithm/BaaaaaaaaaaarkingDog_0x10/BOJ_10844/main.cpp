
#include <bits/stdc++.h>

int n;
constexpr int MAX = 101;
constexpr int Modulo = 1000000000;

long long dp[MAX][10];

// dp[i][j] 는 i번째 자리의 j의 숫자가 온다.?

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    // 0으로 시작하는 수는 계단수가 아니므로

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;

    // 자리수를 1부터 n자리 까지 해야하고
    // 숫자를 0부터 9까지 해야하는건가?

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            // dp[i][j] =

            // dp[2][0] = dp[1][1];
            // dp[2][1] = dp[1][0] + dp[1][2];
            // dp[2][2] = dp[1][1] + dp[1][3];
            // dp[2][3] = dp[1][2] + dp[1][4];
            // dp[2][4] = dp[1][3] + dp[1][5];

            // dp[2][9] =
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][1] % Modulo;
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][8] % Modulo;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] % Modulo + dp[i - 1][j + 1] % Modulo;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        count = count % Modulo + dp[n][i] % Modulo;
    }

    std::cout << count % Modulo;

    // int nn;
    // std::cin >> nn;

    return 0;
}