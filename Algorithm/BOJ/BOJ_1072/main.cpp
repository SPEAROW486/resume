
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

long long x, y;
int z;

int main()
{
    // FASTIO;
    std::cin >> x >> y;
    z = (y * 100) / x;

    if (z >= 99)
    {
        std::cout << "-1\n";
        return 0;
    }

    long long left = 1;
    long long right = 1e9;
    long long ans = -1;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int tmp = ((y + mid) * 100) / (x + mid);
        if (tmp > z)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}