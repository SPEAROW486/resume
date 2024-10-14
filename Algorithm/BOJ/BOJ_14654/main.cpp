#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14654

int vs(int a, int b)
{
    // 가위바위보 승리 규칙
    if (a == b)
        return 0;
    if ((a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1))
    {
        return 1;
    }
    return -1;
}

int main()
{
    FASTIO;

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> matches(n);

    // 각 팀의 패 선택 입력
    for (int i = 0; i < n; ++i)
    {
        std::cin >> matches[i].first;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> matches[i].second;
    }

    int win = 0, cnt = 0, ans = 0;

    for (int i = 0; i < n; ++i)
    {
        int result = vs(matches[i].first, matches[i].second);

        if (result == 0)
        {
            result = -1 * win; // 비길 때 이전 승리자 패배 처리
        }

        if (result == win)
        {
            ++cnt; // 연속 승리 증가
        }
        else
        {
            cnt = 1; // 새로운 승리 시작
            win = result;
        }

        ans = std::max(ans, cnt); // 최대 연승 갱신
    }

    std::cout << ans << '\n';
    return 0;
}
