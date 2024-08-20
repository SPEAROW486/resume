
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<double> v;

constexpr int MAX = 10001;
double dp[MAX];

int main()
{
    // FASTIO;
    std::cin >> n;

    v.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    dp[1] = v[1];

    for (int i = 2; i <= n; ++i)
    {
        if (dp[i - 1] * v[i] > v[i])
        {
            dp[i] = dp[i - 1] * v[i];
        }
        else
        {
            dp[i] = v[i];
        }
    }

    double max = *std::max_element(dp, dp + MAX);
    std::cout << std::fixed << std::setprecision(3) << max;

    return 0;
}