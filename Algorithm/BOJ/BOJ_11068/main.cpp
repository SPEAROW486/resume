
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int t, n;
std::vector<int> v;

bool solve(int decimal, int base)
{
    std::vector<int> result;

    while (decimal > 0)
    {
        result.push_back(decimal % base);
        decimal /= base;
    }

    int lidx = 0;
    int ridx = result.size() - 1;
    for (int i = 0; i < result.size() / 2; ++i)
    {
        if (result[lidx] != result[ridx])
        {
            return false;
        }
        ++lidx;
        --ridx;
    }

    return true;
}

int main()
{
    FASTIO;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        bool ans = false;
        for (int i = 2; i <= 64; ++i)
        {
            ans = solve(n, i);
            if (ans)
            {
                break;
            }
        }
        std::cout << static_cast<int>(ans) << "\n";
    }
    // int nn;
    // std::cin >> nn;

    return 0;
}
