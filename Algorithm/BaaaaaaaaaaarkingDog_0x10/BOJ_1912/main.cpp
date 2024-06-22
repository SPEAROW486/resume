
#include <bits/stdc++.h>

int n;
constexpr int MAX = 100001;
int dp[MAX];
int buf[MAX];

// N이 최대 10만이기때문에 N^2이나 2차원 배열은 쓸수가없을듯.
// 뭔가 최대값을 찾아서 그런걸로 하겠따 라고 하면 답이없는 사고방식인거같고...

// dp[i] = i번째 원소를 마지막으로 하는 최대 연속합

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> buf[i];
    }

    dp[1] = buf[1];
    int max = buf[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = std::max(dp[i - 1] + buf[i], buf[i]);
        max = std::max(dp[i], max);
    }

    std::cout << max;

    int nn;
    std::cin >> nn;
    return 0;
}