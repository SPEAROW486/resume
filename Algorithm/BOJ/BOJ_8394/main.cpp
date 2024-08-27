
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MAX = 10000001;
constexpr int MOD = 10;
long long dp[MAX];

int main()
{
    FASTIO;
    std::cin >> n;

    dp[0] = 0; // 별의미없음
    dp[1] = 1; // 아무랑도 안하는 케이스가 있기 때문에 1이됨.
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;
    }

    std::cout << dp[n] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}