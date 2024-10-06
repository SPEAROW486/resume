#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 4101

int main()
{
    FASTIO;

    int a, b;

    while (true)
    {
        std::cin >> a >> b;

        // 입력이 0 0이면 종료
        if (a == 0 && b == 0)
        {
            break;
        }

        // a가 b보다 크면 "Yes" 출력
        if (a > b)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
