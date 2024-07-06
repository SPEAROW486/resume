
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 10; // 100001;
int n, k;
int dp[MAX];
int items[MAX];

int main()
{
    // FASTIO;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int w, v;
        std::cin >> w >> v;
        dp[w] = v;
        items[w] = v;
    }

    for (int i = 3; i <= k; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (i == 2 * j)
            {
                continue;
            }
            dp[i] = std::max(dp[i], dp[i - j] + dp[j]);
        }
    }

    // 3,4 3,5 3,6
    std::cout << *std::max_element(dp, dp + MAX);

    int nn;
    std::cin >> nn;

    return 0;
}