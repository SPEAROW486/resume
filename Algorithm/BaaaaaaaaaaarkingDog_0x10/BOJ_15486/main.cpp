
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1500002;
int dp[MAX];
int ti[MAX];
int pi[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    // dp[i] 는 i일부터 n일까지 일한 수익

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> ti[i] >> pi[i];
    }

    // i번째 날에 일을 못하면 i번째~N번쨰 까지의 수익은 i+1 ~ N번쨰랑 같다.
    // 일을 할 수 있으면 i번쨰 날의 수익 + i번쨰 상담하면 소요시간이 지난 후의 수익구간
    // i가 5일차고 소요시간이 2일이라고 치면
    // dp[5] = 5일차 수익 + 7일차부터 n일차까지의 수익
    for (int i = n; i > 0; --i)
    {
        if (i + ti[i] <= n + 1)
        {
            dp[i] = std::max(dp[i + 1], pi[i] + dp[i + ti[i]]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    std::cout << *std::max_element(&dp[1], &dp[n + 1]);

    // int nn;
    // std::cin >> nn;
    return 0;
}