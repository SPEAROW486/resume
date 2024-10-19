#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 18406

int main() {
    FASTIO;

    std::string n;
    std::cin >> n;

    int half = n.size() / 2;
    int left_sum = 0, right_sum = 0;

    // 왼쪽 절반 합 계산
    for (int i = 0; i < half; ++i) {
        left_sum += n[i] - '0';
    }

    // 오른쪽 절반 합 계산
    for (int i = half; i < n.size(); ++i) {
        right_sum += n[i] - '0';
    }

    // 두 합이 같은지 비교
    if (left_sum == right_sum) {
        std::cout << "LUCKY\n";
    } else {
        std::cout << "READY\n";
    }

    return 0;
}
