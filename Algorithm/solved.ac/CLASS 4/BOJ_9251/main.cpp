
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001;
int dp[MAX][MAX]; // dp[i][j] = s1[i] == s2[j]가 같으면 까지는 맞았는데 점화식을 못세웠는데.. 표를 보니까 규칙성이 있더라..
int main()
{
    FASTIO;

    std::string s1;
    std::string s2;

    std::cin >> s1 >> s2;
    for (int i = 1; i <= s1.length(); ++i)
    {
        for (int j = 1; j <= s2.length(); ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int max = *std::max_element(&dp[0][0], &dp[s1.size()][s2.size() + 1]);
    std::cout << max;

    // int nn;
    // std::cin >> nn;
    return 0;
}