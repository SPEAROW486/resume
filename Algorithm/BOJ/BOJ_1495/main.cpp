#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1495

int main()
{
    FASTIO;

    int n, s, m;
    std::cin >> n >> s >> m;

    std::vector<int> volumes(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> volumes[i];
    }

    // dp[i][j]는 i번째 곡에서 볼륨이 j일 수 있는지 여부를 저장하는 배열
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
    dp[0][s] = true; // 시작 볼륨 설정

    // dp 테이블 갱신
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (dp[i][j])
            {
                if (j + volumes[i] <= m)
                {
                    dp[i + 1][j + volumes[i]] = true;
                }
                if (j - volumes[i] >= 0)
                {
                    dp[i + 1][j - volumes[i]] = true;
                }
            }
        }
    }

    // 마지막 곡에서 가능한 최대 볼륨 찾기
    int result = -1;
    for (int i = 0; i <= m; ++i)
    {
        if (dp[n][i])
        {
            result = i;
        }
    }

    std::cout << result << '\n';
    return 0;
}
