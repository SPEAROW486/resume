
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<int> v;

int main()
{
    FASTIO;

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    int lidx = 0;
    int ridx = v.size() - 1;

    int ans = 0;
    while (lidx < ridx)
    {
        int tmp = v[lidx] + v[ridx];
        if (tmp == m)
        {
            ++ans;
            ++lidx;
            --ridx;
        }
        else if (tmp < m)
        {
            ++lidx;
        }
        else
        {
            --ridx;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}