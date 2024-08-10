
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, d;

int main()
{
    FASTIO;
    std::cin >> n >> d;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = i;

        while (tmp > 0)
        {
            if ((tmp % 10) == d)
            {
                ++ans;
            }

            tmp /= 10;
        }
    }

    std::cout << ans << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}