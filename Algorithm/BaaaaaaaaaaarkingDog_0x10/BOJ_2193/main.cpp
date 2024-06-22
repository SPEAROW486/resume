
#include <bits/stdc++.h>

int n;
constexpr int MAX = 91;
long long dp[MAX][2];

// dp[i][0] = i번째 자리에 0이 올수 있는 경우
// dp[i][1] = i번째 자리에 1이 올수 있는 경우

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    std::cout << dp[n][0] + dp[n][1];

    // int nn;
    // std::cin >> nn;
    return 0;
}