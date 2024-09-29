#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2156

int main() {
    FASTIO;
    
    int n;
    std::cin >> n;

    std::vector<int> wine(n + 1);
    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        std::cin >> wine[i];
    }

    if (n == 1) {
        std::cout << wine[1] << "\n";
        return 0;
    }

    // 초기값 설정
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    // dp 배열 채우기
    for (int i = 3; i <= n; i++) {
        dp[i] = std::max({dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]});
    }

    std::cout << dp[n] << "\n";
    return 0;
}
