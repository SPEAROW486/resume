
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    int n, m;

    while (true)
    {
        std::cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }

        std::unordered_map<int, int> map;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            ++map[tmp];
        }

        for (int i = 0; i < m; ++i)
        {
            int tmp;
            std::cin >> tmp;
            ++map[tmp];
        }

        int ans = 0;
        for (const std::pair<int, int> &cd : map)
        {
            if (cd.second >= 2)
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