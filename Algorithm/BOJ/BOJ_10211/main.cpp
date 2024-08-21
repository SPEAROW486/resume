
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int main()
{
    // FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        int n;
        std::cin >> n;

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        std::vector<int> v;
        v.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        dp[1] = v[1];
        for (int i = 2; i <= n; ++i)
        {
            if (dp[i - 1] + v[i] > v[i])
            {
                dp[i] = dp[i - 1] + v[i];
            }
            else
            {
                dp[i] = v[i];
            }
        }

        // 항이 1개고 음수일때
        // dp[0] 에는 0이 들어있기 때문에
        // 검색 범위를 수정해주었음.
        // 혹은 dp[0]을 문제에서 주어지는 최솟값 보다 작게 두면 될듯.
        std::cout << *std::max_element(dp + 1, dp + n + 1) << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}