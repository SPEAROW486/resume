#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2302

int main()
{
    FASTIO;

    // 입력값 선언
    int n, m;
    std::cin >> n >> m;

    std::vector<int> vipSeats(m); // VIP 좌석 위치
    for (int i = 0; i < m; ++i)
    {
        std::cin >> vipSeats[i];
    }

    // dp[i]는 i개의 연속된 좌석이 있을 때 가능한 배치의 경우의 수를 의미
    std::vector<int> dp(n + 1, 1);
    dp[1] = 1; // 좌석이 1개일 때의 경우의 수는 1

    // 좌석이 2개일 때의 경우의 수는 2가지: (AB) 혹은 (BA)
    if (n >= 2)
    {
        dp[2] = 2;
    }

    // DP 점화식으로 모든 경우의 수를 계산
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // VIP 좌석이 있는 구간을 기준으로 각 구간별로 경우의 수를 곱해준다.
    int result = 1;
    int lastIndex = 0;

    for (int vip : vipSeats)
    {
        int length = vip - lastIndex - 1; // VIP 좌석 이전까지의 구간 길이
        result *= dp[length];
        lastIndex = vip; // 마지막 VIP 좌석 갱신
    }

    // 마지막 VIP 좌석 이후의 구간 처리
    result *= dp[n - lastIndex];

    std::cout << result << "\n";
    return 0;
}
