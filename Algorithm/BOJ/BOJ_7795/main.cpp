
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int main()
{
    FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        std::vector<int> b(m);
        for (int i = 0; i < m; ++i)
        {
            std::cin >> b[i];
        }

        std::sort(a.begin(), a.end(), std::greater<>());
        std::sort(b.begin(), b.end(), std::greater<>());

        int ans = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < b.size(); ++j)
            {
                if (b[j] >= a[i])
                {
                    continue;
                }

                ++ans;
            }
        }

        std::cout << ans << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}