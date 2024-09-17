#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 16493

int main()
{
    FASTIO;

    int N, M;
    std::cin >> N >> M; // N: 남은 날짜, M: 챕터 수

    std::vector<int> days(M + 1), pages(M + 1);

    for (int i = 1; i <= M; ++i)
    {
        std::cin >> days[i] >> pages[i]; // 각 챕터의 소요 시간과 페이지 수 입력
    }

    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, 0)); // dp 테이블 초기화

    // 챕터마다 DP 계산
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            dp[i][j] = dp[i - 1][j]; // 챕터를 선택하지 않았을 때
            if (j >= days[i])
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - days[i]] + pages[i]); // 챕터를 선택했을 때
            }
        }
    }

    std::cout << dp[M][N] << '\n'; // 최대 페이지 수 출력

    // int nn;
    // std::cin >> nn;
    return 0;
}
