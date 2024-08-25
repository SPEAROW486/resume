
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long long tn;
        std::cin >> tn;
        std::unordered_map<long long, int> map;

        long long land_num = 0;
        long long max_num = LLONG_MIN;
        for (int j = 0; j < tn; ++j)
        {
            long long tmp;
            std::cin >> tmp;
            ++map[tmp];

            if (map[tmp] > max_num)
            {
                max_num = map[tmp];
                land_num = tmp;
            }
        }

        int half = tn / 2;

        bool win = max_num > half;
        if (win)
        {
            std::cout << land_num << "\n";
        }
        else
        {
            std::cout << "SYJKGW\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}