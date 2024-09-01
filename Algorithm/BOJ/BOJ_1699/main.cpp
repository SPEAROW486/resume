
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1699
constexpr int MAX = 100001;
int dp[MAX];

int main()
{
    FASTIO;
    int n;
    std::cin >> n;

    // 이런식으로 가면 i가 어떤 제곱수면 무조건 1임
    // 1. i의 정수 제곱근을 구한다
    // 2. 정수 제곱근을 제곱한 결과가 i랑 같으면 1개 항으로 표현 가능
    // 3. 다르다면 dp[정수제곱근의 결과] + dp[i-정수제곱근의결과]로 표현가능?
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = i; // 최악의 경우 모든 수를 1^2로만 표현하는 경우
        for (int j = 1; j * j <= i; ++j)
        {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    std::cout << dp[n] << '\n';

    // int nn;
    // std::cin >> nn;

    return 0;
}