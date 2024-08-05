
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;

bool solve(int i)
{
    std::unordered_map<int, int> map;
    int tmp = i;
    while (tmp > 0)
    {
        int digit = tmp % 10;
        tmp /= 10;
        ++map[digit];

        if (map[digit] >= 2)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    //     FASTIO;

    while (std::cin >> n >> m)
    {
        int ans = 0;
        for (int i = n; i <= m; ++i)
        {
            if (solve(i))
            {
                ++ans;
            }
        }

        std::cout << ans << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}