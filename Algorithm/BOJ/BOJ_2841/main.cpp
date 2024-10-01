#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2841

int main()
{
    FASTIO;

    int N, P;
    std::cin >> N >> P;

    // 6개의 줄을 위한 스택 배열 선언
    std::stack<int> guitarStrings[6];
    int moves = 0;

    for (int i = 0; i < N; ++i)
    {
        int line, fret;
        std::cin >> line >> fret;

        // 줄의 인덱스를 0부터 시작하게 맞춤
        --line;

        // 현재 줄에서 프렛을 누르고 있는 상태라면 빼줌
        while (!guitarStrings[line].empty() && guitarStrings[line].top() > fret)
        {
            guitarStrings[line].pop();
            ++moves;
        }

        // 이미 같은 프렛을 누르고 있다면 패스
        if (!guitarStrings[line].empty() && guitarStrings[line].top() == fret)
        {
            continue;
        }

        // 새로운 프렛을 누르는 경우
        guitarStrings[line].push(fret);
        ++moves;
    }

    std::cout << moves << "\n";

    return 0;
}
