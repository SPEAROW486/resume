
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1001;
int dp[MAX];
int buf[MAX];

// dp[i] = i번째 원소를 마지막 원소로 하는 가장 긴 부분 수열의 길이

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> buf[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            if (buf[i] > buf[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << *std::max_element(&dp[1], &dp[n + 1]);

    // int nn;
    // std::cin >> nn;
    return 0;
}