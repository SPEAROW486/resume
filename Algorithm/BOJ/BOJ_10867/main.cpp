
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::set<int> set;

int main()
{
    FASTIO;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;

        set.insert(tmp);
    }

    for (auto iter = set.begin(); iter != set.end(); ++iter)
    {
        std::cout << *iter << " ";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
