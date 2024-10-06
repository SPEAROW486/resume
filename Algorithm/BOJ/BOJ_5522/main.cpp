#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 5522
int main()
{
    FASTIO;

    int sum = 0; // 점수의 합을 저장할 변수
    for (int i = 0; i < 5; ++i)
    {
        int score;
        std::cin >> score; // 각 라운드의 점수 입력
        sum += score;      // 입력된 점수를 합산
    }

    std::cout << sum << '\n'; // 최종 점수 출력
    return 0;
}
