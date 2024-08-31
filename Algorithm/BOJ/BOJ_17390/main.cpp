#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, q;
std::vector<int> v;
constexpr int MAX = 300001;
int dp[MAX];

int main()
{
    FASTIO;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + v[i - 1];
    }

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        std::cout << dp[r] - dp[l - 1] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
