#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 27323

int main()
{
    FASTIO;

    // 가로와 세로 입력 받기
    int a, b;
    std::cin >> a >> b;

    // 직사각형의 넓이 출력
    std::cout << a * b << '\n';

    return 0;
}
