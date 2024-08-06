
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int t, j, n;

int main()
{
    FASTIO;
    std::cin >> t;
    while (t--)
    {
        std::cin >> j >> n;
        std::vector<int> box;

        for (int i = 0; i < n; ++i)
        {
            int r, c;
            std::cin >> r >> c;
            box.push_back(r * c);
        }

        std::sort(box.begin(), box.end(), std::greater<int>());

        int ans = 0;
        int idx = 0;
        while (true)
        {
            ++ans;
            j -= box[idx];
            ++idx;

            if (j <= 0)
            {
                break;
            }
        }

        std::cout << ans << "\n";
    }
    // int nn;
    // std::cin >> nn;

    return 0;
}
