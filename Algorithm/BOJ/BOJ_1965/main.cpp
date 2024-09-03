
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1965
// DP??

int n;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    std::vector<int> dp(n, 1); // 모든 상자에 대해 최장 증가 부분 수열의 길이를 1로 초기화

    // j -> i까지 증가하는 부분 찾기
    for (int i = 1; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = *std::max_element(dp.begin(), dp.end());

    std::cout << max_length << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}