
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
int main()
{
    FASTIO;

    std::cin >> n >> m;

    if (n == 1)
    {
        std::cout << 1;
    }
    else if (n == 2)
    {
        std::cout << std::min(4, (m + 1) / 2);
    }
    else if (m < 7)
    {
        std::cout << std::min(4, m);
    }
    else
    {
        std::cout << m - 2;
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}