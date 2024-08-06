
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int k;

constexpr int MAX = 46;
constexpr int A = 0;
constexpr int B = 1;

int dp[MAX][2];

int main()
{
    FASTIO;
    std::cin >> k;

    std::string s("A");

    dp[0][A] = 1;
    dp[0][B] = 0;
    for (int i = 1; i <= k; ++i)
    {
        dp[i][A] = dp[i - 1][B];
        dp[i][B] = dp[i - 1][A] + dp[i - 1][B];
    }

    std::cout << dp[k][A] << " " << dp[k][B] << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}