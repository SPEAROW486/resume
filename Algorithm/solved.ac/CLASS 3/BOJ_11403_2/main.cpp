#include <bits/stdc++.h>

constexpr int MAX = 101;
int n;
int dp[MAX][MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int l;
            std::cin >> l;

            if (l == 1)
            {
                dp[i][j] = 1;
            }
            if (i == j)
            {
                dp[i][j] = 0; // 자기 자신으로 가는 경로는 0으로 설정
            }
        }
    }

    // 플로이드-와샬 알고리즘 적용
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dp[i][k] && dp[k][j])
                {
                    dp[i][j] = dp[i][k] && dp[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
