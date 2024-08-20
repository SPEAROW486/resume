
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;

    std::cin >> n;

    int tmp = n;
    int digit = 0;
    while (tmp > 0)
    {
        tmp /= 10;
        ++digit;
    }

    int ans = 0;
    while (digit)
    {
        int tmp = pow(10, digit - 1);
        int cnt = n - tmp + 1;
        ans += (cnt * digit);
        n -= cnt;
        --digit;
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}