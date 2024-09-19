
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 18353
int n;
std::vector<int> v;
std::vector<int> dp;

int main()
{
    FASTIO;

    std::cin >> n;
    v.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        // 각각의 부분수열은 1로 초기화
        dp[i] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[j] > v[i])
            {
                // dp[i] 값은 현재 값과 dp[j] + 1 중 큰 값으로 갱신
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = *std::max_element(dp.begin(), dp.end());
    std::cout << n - max_length << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}