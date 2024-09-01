
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1535

int main()
{
    FASTIO;
    int n;
    std::cin >> n;

    std::vector<int> L(n + 1), J(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> L[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> J[i];
    }

    // 최대 체력은 100까지만 고려
    int max_health = 100;
    std::vector<int> dp(max_health + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = max_health; j >= L[i]; --j)
        {
            dp[j] = std::max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    // 체력이 0이 되지 않도록, 소모한 체력이 100 미만 경우의 최대 기쁨을 찾는다.
    int result = *std::max_element(dp.begin(), dp.end() - 1);

    std::cout << result << std::endl;

    // int nn;
    // std::cin >> nn;

    return 0;
}