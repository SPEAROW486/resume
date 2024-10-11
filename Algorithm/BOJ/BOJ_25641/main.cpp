#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 25641

int main() {
    FASTIO;

    int n; // 소떡소떡의 길이
    std::string s; // 소떡소떡 문자열

    std::cin >> n >> s;

    int s_count = 0, t_count = 0;

    // 전체 문자열에서 's'와 't'의 개수를 카운트
    for (char c : s) {
        if (c == 's') {
            s_count++;
        } else if (c == 't') {
            t_count++;
        }
    }

    // 앞에서부터 s와 t의 균형을 맞추기 위해 제거
    for (int i = 0; i < n; ++i) {
        if (s_count == t_count) {
            std::cout << s.substr(i) << '\n';
            break;
        }

        // 개수를 감소시키면서 균형을 맞추기
        if (s[i] == 's') {
            s_count--;
        } else if (s[i] == 't') {
            t_count--;
        }
    }

    return 0;
}
