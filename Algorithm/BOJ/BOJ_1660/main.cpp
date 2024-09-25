#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1660

int main() {
    FASTIO;

    // 테트라헤드론 개수를 저장하는 벡터
    std::vector<int> tetra;
    
    // 테트라헤드론의 개수를 계산
    int cnt = 1, sum = 0;
    for (int i = 1; ; i++) {
        sum += i * (i + 1) / 2;
        if (sum > 300000) break;
        tetra.push_back(sum);
    }
    
    // DP 테이블 초기화 (최대 300000까지 가능)
    std::vector<int> dp(300001, INT_MAX);
    dp[0] = 0; // 0을 만드는 데 필요한 최소 갯수는 0

    // DP를 이용하여 최소 테트라헤드론 개수 계산
    for (int i = 0; i < tetra.size(); i++) {
        for (int j = tetra[i]; j <= 300000; j++) {
            dp[j] = std::min(dp[j], dp[j - tetra[i]] + 1);
        }
    }

    // n을 입력받고 결과 출력
    int n;
    std::cin >> n;
    std::cout << dp[n] << '\n';

    return 0;
}
