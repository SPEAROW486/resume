#include <bits/stdc++.h>
#define FASTIO                              \
    std::ios_base::sync_with_stdio(false);  \
    std::cin.tie(NULL)

// BOJ : 17944

int main() {
    FASTIO;

    int N, M;
    std::cin >> N >> M;
    M -= 1;  // 0-based indexing 처리

    int cycle = 4 * N - 2;  // 전체 주기 계산
    int position = M % cycle;  // 현재 차례 계산

    if (position < 2 * N) {
        std::cout << position + 1 << "\n";  // 팔이 올라가는 상태
    } else {
        std::cout << 2 * N - (position - 2 * N + 1) << "\n";  // 팔이 내려가는 상태
    }

    return 0;
}
