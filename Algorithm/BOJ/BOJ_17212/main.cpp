#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)
constexpr int MAX = 100001;
constexpr int INF = 1e9;
int n;
int dp[MAX]; // dp[i] == i원을 지불하기 위한 동전의 최소 개수

int main()
{
    FASTIO;
    std::cin >> n;
    std::fill(dp, dp + MAX, INF);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 3;
    dp[7] = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (i >= 1)
        {
            dp[i] = std::min(dp[i], dp[i - 1] + 1); // 1원을 추가하는 경우
        }
        if (i >= 2)
        {
            dp[i] = std::min(dp[i], dp[i - 2] + 1); // 2원을 추가하는 경우
        }
        if (i >= 5)
        {
            dp[i] = std::min(dp[i], dp[i - 5] + 1); // 5원을 추가하는 경우
        }
        if (i >= 7)
        {
            dp[i] = std::min(dp[i], dp[i - 7] + 1); // 7원을 추가하는 경우
        }
    }

    std::cout << dp[n] << "\n";

    return 0;
}
