
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001;
int dp[MAX];
int sequence[MAX];
int n;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> sequence[i];
        dp[i] = 1;
    }

    // dp[i] = 1부터 i번쨰 요소까지의 감소하는 부분 수열의 길이
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (sequence[i] < sequence[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << *std::max_element(&dp[0], &dp[MAX]);

    // int nn;
    // std::cin >> nn;
    return 0;
}