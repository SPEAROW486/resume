
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

constexpr int MAX = 1001; // 서로 1개씩 가져간다고치면 최대 500턴이니까?

bool dp[MAX]; // dp[i] : i개의 돌이 남았을때 true면 상근이의 승리

int main()
{
    FASTIO;

    std::cin >> n;

    dp[0] = false;
    dp[1] = true;
    dp[3] = true;
    dp[4] = true;

    for (int i = 5; i <= n; ++i)
    {
        if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
        {
            dp[i] = true;
        }
    }

    // 결과 출력
    if (dp[n] == 1)
    {
        std::cout << "SK\n";
    }
    else
    {
        std::cout << "CY\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}