
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 200001;
int n;
std::vector<int> v;
int dp[MAX]; // dp[i], i번째 날 이전에 가장 싸게 사서 i번째 날의 팔때 최대 이득

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    dp[0] = 0;
    int min = v[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] = std::max(dp[i - 1], v[i] - min); // 여태까지 얻은 이익이 큰지, 이번에 얻은 이익이 큰지
        min = std::min(min, v[i]);
    }

    std::cout << dp[n - 1];

    // int nn;
    // std::cin >> nn;
    return 0;
}