#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int m;
std::vector<long long> v;

int main()
{
    FASTIO;
    std::cin >> m;
    v.push_back(0);

    long long sum = 0;
    long long xr = 0;

    for (int i = 0; i < m; ++i)
    {
        int query;
        std::cin >> query;

        if (query == 1)
        {
            int x;
            std::cin >> x;
            sum += x;
            xr ^= x;
        }
        else if (query == 2)
        {
            int x;
            std::cin >> x;
            sum -= x;
            xr ^= x;
        }
        else if (query == 3)
        {
            std::cout << sum << "\n";
        }
        else
        {
            std::cout << xr << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
