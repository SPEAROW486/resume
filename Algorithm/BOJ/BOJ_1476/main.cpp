
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int e, s, m;

int main()
{
    FASTIO;
    std::cin >> e >> s >> m;

    int ans = 1;

    int se = 1;
    int ss = 1;
    int sm = 1;
    while (true)
    {
        if (se == e && ss == s && sm == m)
        {
            break;
        }

        ++se;
        ++ss;
        ++sm;

        if (se > 15)
        {
            se = 1;
        }

        if (ss > 28)
        {
            ss = 1;
        }

        if (sm > 19)
        {
            sm = 1;
        }
        ++ans;
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}