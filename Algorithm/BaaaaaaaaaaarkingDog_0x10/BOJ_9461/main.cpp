
#include <bits/stdc++.h>

int n;
constexpr int MAX = 101;
long long dp[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for (int i = 6; i <= 100; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int tc;
    std::cin >> tc;
    while (tc--)
    {
        std::cin >> n;
        std::cout << dp[n] << "\n";
    }

    // int nn;
    // std::cin >> n;
    return 0;
}