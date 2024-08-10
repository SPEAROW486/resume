
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int a, t, type;
int solve()
{
    int bbun = 0;
    int degi = 0;
    int cnt = 2;

    while (true)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (i % 2 == 0)
            {
                ++bbun;
            }
            else
            {
                ++degi;
            }

            if (bbun == t && type == 0)
            {
                return (bbun + degi - 1) % a;
            }
            if (degi == t && type == 1)
            {
                return (bbun + degi - 1) % a;
            }
        }

        for (int i = 0; i < cnt; ++i)
        {
            ++bbun;
            if (bbun == t && type == 0)
            {
                return (bbun + degi - 1) % a;
            }
        }

        for (int i = 0; i < cnt; ++i)
        {
            ++degi;
            if (degi == t && type == 1)
            {
                return (bbun + degi - 1) % a;
            }
        }
        ++cnt;
    }
    return 0;
}

int main()
{
    // FASTIO;

    std::cin >> a >> t >> type;
    std::cout << solve() << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}