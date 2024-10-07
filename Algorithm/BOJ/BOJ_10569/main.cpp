#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 10569

int main() {
    FASTIO;

    int T;
    std::cin >> T;  // 테스트 케이스의 수 입력

    while (T--) {
        int V, E;
        std::cin >> V >> E;  // V: 꼭짓점의 수, E: 모서리의 수 입력

        // 다면체의 면의 수 계산: F = E - V + 2
        int F = E - V + 2;

        std::cout << F << "\n";  // 결과 출력
    }

    return 0;
}
