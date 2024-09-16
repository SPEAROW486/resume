#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14650

int n;
int ans;

void back(int sum, int digit)
{
    // 자릿수가 n에 도달한 경우
    if (digit == n)
    {
        // 3으로 나누어 떨어지면 답을 증가시킴
        if (sum % 3 == 0)
        {
            ++ans;
        }
        return;
    }

    // 첫 번째 자리는 0이 될 수 없으므로 예외 처리
    for (int i = (digit == 0 ? 1 : 0); i < 3; ++i)
    {
        back(sum + i, digit + 1);
    }
}

int main()
{
    FASTIO;
    std::cin >> n;

    ans = 0;
    back(0, 0);

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
