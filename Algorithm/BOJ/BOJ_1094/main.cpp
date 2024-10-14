#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1094

int main() {
    FASTIO;

    int X;
    std::cin >> X;

    int count = 0;
    while (X > 0) {
        // X의 이진수 표현에서 1의 개수를 세기
        if (X % 2 == 1) {
            count++;
        }
        X /= 2;
    }

    std::cout << count << '\n';
    return 0;
}
