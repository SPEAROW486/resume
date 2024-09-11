
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

constexpr int MAX = 1001;
int dp[MAX]; // dp[i]는 0부터 i까지 증가하는 부분 수열의 길이

int main()
{
    // FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);

        // 각자의 기본값은 1 다 각각의 부분수열이니까
        dp[i] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // 0부터 i번째 요소까지의 값을 비교해서 i번째 요소가 더 클때에만
            if (v[j] < v[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << *std::max_element(dp, dp + MAX) << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}