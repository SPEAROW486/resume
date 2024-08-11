
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 11;
int dp[MAX]; // dp[i] = i년째에 원금에 i년째 이자를 더한 값
int h, y;

int main()
{
    FASTIO;

    std::cin >> h >> y;

    dp[0] = h;
    for (int i = 1; i <= y; ++i)
    {
        dp[i] = static_cast<int>(dp[i - 1] * 1.05);
        if (i >= 3)
        {
            dp[i] = std::max(dp[i], static_cast<int>(dp[i - 3] * 1.2));
        }
        if (i >= 5)
        {
            dp[i] = std::max(dp[i], static_cast<int>(dp[i - 5] * 1.35));
        }
    }

    std::cout << dp[y] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}