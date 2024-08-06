
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

constexpr int MAX = 1001;

int dp[MAX]; // 돌이 n개가 있을떄 몇번의 턴이 오고가는가

int main()
{
    // FASTIO;
    std::cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = std::min(dp[i - 1] + 1, dp[i - 3] + 1);
    }

    if (dp[n] % 2 == 0)
    {
        std::cout << "CY\n";
    }
    else
    {
        std::cout << "SK\n";
    };

    int nn;
    std::cin >> nn;
    return 0;
}