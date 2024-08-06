
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::unordered_set<int> set;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        set.insert(tmp);
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;

        if (set.find(tmp) != set.end())
        {
            std::cout << 1 << " ";
        }
        else
        {
            std::cout << 0 << " ";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}