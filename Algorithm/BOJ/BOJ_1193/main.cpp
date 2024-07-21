
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    int x;
    std::cin >> x;

    // x가 어디 대각선에 속하는지는 풀이보고 알았음.
    int i = 1;
    while (x > i)
    {
        x -= i;
        ++i;
    }

    // 여기는 방향이 이해가안갔는데 문제를 잘못읽어서 그랬음..
    if (i % 2 == 0)
    {
        std::cout << x << "/" << i - x + 1;
    }
    else
    {
        std::cout << i - x + 1 << "/" << x;
    }

    return 0;
}