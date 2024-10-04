#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 16564

int main() {
    FASTIO;

    int N, K;
    std::cin >> N >> K;

    std::vector<int> levels(N);
    for (int i = 0; i < N; i++) {
        std::cin >> levels[i];
    }

    // 모든 레벨을 오름차순 정렬
    std::sort(levels.begin(), levels.end());

    long long left = levels[0], right = levels[0] + K;
    long long result = levels[0];

    // 이분탐색을 통해 가능한 최대 레벨을 찾음
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long required_points = 0;

        for (int i = 0; i < N; i++) {
            if (levels[i] < mid) {
                required_points += (mid - levels[i]);
            }
        }

        // 필요한 포인트가 주어진 포인트 K보다 작거나 같으면 mid를 갱신
        if (required_points <= K) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << result << "\n";

    return 0;
}
