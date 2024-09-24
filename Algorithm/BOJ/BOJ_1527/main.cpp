#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1527

// 재귀적으로 4와 7로 이루어진 모든 숫자를 생성하는 함수
void generate_lucky_numbers(long long current, long long L, long long R, int &count)
{
    if (current > R)
    {
        return; // 현재 수가 R을 넘으면 더 이상 탐색할 필요 없음
    }

    if (current >= L && current <= R)
    {
        count++; // 범위 내에 있으면 카운트 증가
    }

    // 다음 숫자를 생성 (4를 붙이거나 7을 붙임)
    generate_lucky_numbers(current * 10 + 4, L, R, count);
    generate_lucky_numbers(current * 10 + 7, L, R, count);
}

int main()
{
    FASTIO;

    long long L, R;
    std::cin >> L >> R; // L과 R 입력 받음

    int count = 0;

    // 4와 7로 이루어진 모든 숫자를 탐색 시작
    generate_lucky_numbers(0, L, R, count);

    std::cout << count << '\n'; // 결과 출력

    return 0;
}
