#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;
    std::cin >> n;

    // score, minute;
    std::stack<std::pair<int, int>> stack;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t, score = 0, minute = 0;
        std::cin >> t;
        if (t == 1)
        {
            std::cin >> score >> minute;
        }

        if (t == 0)
        {
            // 하던거 이어서
            if (!stack.empty() && i >= stack.top().second)
            {
                ans += stack.top().first;
                stack.pop();
            }
        }
        else
        {
            // 받자마자 바로 시작
            --minute;
            if (minute == 0)
            {
                ans += score;
            }
            else
            {
                // 안끝났으면 받은 시각 + 남은시간으로 저장.
                stack.push({score, i + minute});
            }
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
