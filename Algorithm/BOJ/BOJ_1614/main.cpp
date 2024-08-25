
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

long long finger, count;
int main()
{
    FASTIO;
    std::cin >> finger >> count;

    long long ans = 0;
    if (finger == 1)
    {
        ans = count * 8;
    }
    else if (finger == 2)
    {
        ans = 1 + 6 * ((count + 1) / 2) + 2 * (count / 2);
    }
    else if (finger == 3)
    {
        ans = 2 + count * 4;
    }
    else if (finger == 4)
    {
        ans = 3 + 2 * ((count + 1) / 2) + 6 * (count / 2);
    }
    else if (finger == 5)
    {
        ans = 4 + 8 * count;
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}