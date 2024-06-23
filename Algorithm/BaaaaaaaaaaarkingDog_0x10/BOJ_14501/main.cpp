
#include <bits/stdc++.h>

int n;
constexpr int MAX = 20;
int dp[MAX];
int ti[MAX];
int pi[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> ti[i] >> pi[i];
    }

    // DP[i] = i번째 날부터 마지막 날까지 얻을 수 있는 최대 수익
    // i번째 날에 상담을 할 수 없다면 그 다음날의 수익으로 대입
    // ex) 6일째에 상담을 못한다면 6일부터 N일까지의 최대 수익이므로, 7일차의 수익을 대입한다.

    for (int i = n; i >= 1; --i)
    {
        if (i + ti[i] - 1 <= n)
        {
            dp[i] = std::max(dp[i + 1], pi[i] + dp[i + ti[i]]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    std::cout << *std::max_element(&dp[1], &dp[n + 1]);

    int nn;
    std::cin >> nn;
    return 0;
}