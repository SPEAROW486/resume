#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2343

int main() {
    FASTIO;

    int n, m;
    std::cin >> n >> m; // 강의의 수와 블루레이의 수

    std::vector<int> lessons(n);
    int total = 0, maxLesson = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> lessons[i];
        total += lessons[i]; // 전체 강의 길이의 합
        if (lessons[i] > maxLesson) {
            maxLesson = lessons[i]; // 가장 긴 강의의 길이
        }
    }

    // 이진 탐색을 통해 최소 블루레이 크기 찾기
    int left = maxLesson, right = total, result = total;

    while (left <= right) {
        int mid = (left + right) / 2; // 블루레이 크기의 중간값
        int count = 1, sum = 0;

        for (int i = 0; i < n; ++i) {
            if (sum + lessons[i] > mid) {
                ++count; // 새로운 블루레이 필요
                sum = lessons[i];
            } else {
                sum += lessons[i];
            }
        }

        if (count <= m) {
            result = mid; // 블루레이 개수가 m 이하일 때, 더 작은 크기를 시도
            right = mid - 1;
        } else {
            left = mid + 1; // 블루레이 개수가 m보다 많으면, 더 큰 크기를 시도
        }
    }

    std::cout << result << '\n';
    return 0;
}
