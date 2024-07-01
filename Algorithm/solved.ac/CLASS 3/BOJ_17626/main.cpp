
#include <bits/stdc++.h>

int n;
constexpr int MAX = 50001;
int dp[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    std::fill(dp, dp + MAX, INT_MAX);

    int i = 1;
    while (i * i <= n)
    {
        dp[i * i] = 1;
        ++i;
    }

    for (int j = 1; j <= n; ++j)
    {
        int k = 1;
        while (k * k < j)
        {
            dp[j] = std::min(dp[j], dp[j - k * k] + 1);
            ++k;
        }
    }

    std::cout << dp[n];

    // int nn;
    // std::cin >> nn;
    return 0;
}