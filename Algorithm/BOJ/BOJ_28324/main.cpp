
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

std::vector<int> v;

constexpr int MAX = 500001; // 500001;
int dp[MAX];                // dp[i] = 도착지점에서 속력이 0이 되기 위한 i지점에서의 현재 속력?

int main()
{
    FASTIO;

    std::cin >> n;

    v.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    // 0의 속력으로 도착해야하기 때문에 마지막 중간 지점에서의 속력은 반드시 1이여야함.
    dp[n] = 1;

    // n-1 지점의 속력은 dp[n] +1이거나 현재 지점의 속도제한 수치에 맞춰야함.

    for (int i = n - 1; i > 0; --i)
    {
        dp[i] = std::min(dp[i + 1] + 1, v[i]);
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += dp[i];
    }

    std::cout << ans;

    int nn;
    std::cin >> nn;
    return 0;
}