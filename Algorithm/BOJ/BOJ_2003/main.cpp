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

    int lidx = 0;
    int ridx = 0;
    int cnt = 0;
    int sum = 0;

    while (ridx <= n)
    {
        if (sum >= m)
        {
            sum -= v[lidx++];
        }
        else
        {
            if (ridx < n)
            {
                sum += v[ridx];
            }
            ++ridx;
        }

        if (sum == m)
        {
            ++cnt;
        }
    }

    std::cout << cnt << "\n";

    return 0;
}
