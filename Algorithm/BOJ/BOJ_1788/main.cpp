
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
constexpr int MOD = 1000000000;
std::unordered_map<int, int> map;

int main()
{
    FASTIO;

    std::cin >> n;

    map[-1] = 1;
    map[0] = 0;
    map[1] = 1;

    if (n > 0)
    {
        for (int i = 2; i <= n; ++i)
        {
            map[i] = ((map[i - 1] % MOD) + (map[i - 2] % MOD)) % MOD;
        }
    }
    else
    {
        for (int i = -1; i >= n; --i)
        {
            map[i] = ((map[i + 2] % MOD) - (map[i + 1] % MOD)) % MOD;
        }
    }

    if (map[n] > 0)
    {
        std::cout << "1\n";
    }
    else if (map[n] < 0)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << "0\n";
    }
    std::cout << abs(map[n]) << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}