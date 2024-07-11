
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int a, b;

// map +bfs로 하는 방법도 있음.
// 아무리 숫자가 커도 모든 범위를 다 쓰는건 아니니까
int main()
{
    FASTIO;
    std::cin >> a >> b;

    int result = 1;

    while (true)
    {
        if (a == b)
        {
            break;
        }

        if (a > b)
        {
            result = -1;
            break;
        }

        if (b % 2 == 0)
        {
            b /= 2;
            ++result;
        }
        else if (b % 10 == 1)
        {
            b = (b - 1) / 10;
            ++result;
        }
        else
        {
            result = -1;
            break;
        }
    }

    std::cout << result;

    // int nn;
    // std::cin >> nn;

    return 0;
}