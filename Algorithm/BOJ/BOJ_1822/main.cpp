
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::set<int> a;
std::set<int> b;

int main()
{
    FASTIO;

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int tmp = 0;
        std::cin >> tmp;
        a.insert(tmp);
    }

    for (int i = 0; i < m; ++i)
    {
        int tmp = 0;
        std::cin >> tmp;
        b.insert(tmp);
    }

    for (auto it : b)
    {
        a.erase(it);
    }

    std::cout << a.size() << "\n";
    for (auto it : a)
    {
        std::cout << it << " ";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}