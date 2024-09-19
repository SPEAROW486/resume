
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 19949

int arr[10];     // 답안을 저장할 배열
int answer = 0;  // 정답 개수를 셀 변수
int correct[10]; // 맞춰야 하는 정답 배열

// 백트래킹을 통해 답안 배열을 채워나감
void solve(int idx, int score)
{
    if (idx == 10)
    {
        if (score >= 5)
        {
            ++answer;
        }
        return;
    }

    for (int i = 1; i <= 5; ++i)
    {
        if (idx >= 2 && arr[idx - 1] == i && arr[idx - 2] == i)
        {
            continue;
        }
        arr[idx] = i;

        solve(idx + 1, score + (i == correct[idx]));
    }
}

int main()
{
    FASTIO;

    // 정답 배열 입력
    for (int i = 0; i < 10; i++)
    {
        std::cin >> correct[i];
    }

    // 백트래킹 시작
    solve(0, 0);

    // 조건을 만족하는 경우의 수 출력
    std::cout << answer << '\n';

    // int nn;
    // std::cin >> nn;
    return 0;
}