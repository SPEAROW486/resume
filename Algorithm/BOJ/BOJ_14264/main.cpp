#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14264

int main()
{
    FASTIO;

    // 한 변의 길이 L 입력
    double L;
    std::cin >> L;

    // 내접한 정삼각형의 넓이 계산
    double area = (std::sqrt(3) / 4) * L * L;

    // 결과 출력
    std::cout << std::fixed << std::setprecision(9) << area << "\n";

    return 0;
}
