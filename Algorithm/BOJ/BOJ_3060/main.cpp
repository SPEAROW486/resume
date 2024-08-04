
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n;
        std::vector<int> v;

        int feed = 0;
        // 1일차
        for (int i = 0; i < 6; ++i)
        {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);

            feed += tmp;
        }

        int ans = 0;
        int bias = 1;
        while (true)
        {
            ++ans;
            if (n - feed * bias < 0)
            {
                break;
            }
            bias *= 4;
        }

        std::cout << ans << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}