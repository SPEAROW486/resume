
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MOD = 1000000007;
constexpr int MAX = 1001;
long long dp[MAX][MAX]; // dp[i][j] = 0,0부터 i,j까지 오는 누적 경우의 수
int n, m;

int main()
{
    FASTIO;
    std::cin >> n >> m;

    // (n,m)을 오른쪽 아래라고 표현했으니까
    // row, col이 반대인건가?

    // base value
    dp[1][1] = 1;
    // 인덱스 범위때문에 1,1부터 시작하는게 좋을듯
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
        }
    }

    std::cout << dp[m][n];

    // int nn;
    // std::cin >> nn;
    return 0;
}