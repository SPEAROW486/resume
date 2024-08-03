
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::vector<std::pair<int, int>> v;

bool cmp(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    if (lhs.second > rhs.second)
    {
        return true;
    }
    return lhs.first < rhs.first;
}

bool cmp2(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    return lhs.first < rhs.first;
}

int main()
{
    FASTIO;
    for (int i = 1; i <= 8; ++i)
    {
        int tmp;
        std::cin >> tmp;

        v.push_back({i, tmp});
    }

    std::sort(v.begin(), v.end(), cmp);

    int ans = 0;
    for (int i = 0; i < 5; ++i)
    {
        ans += v[i].second;
    }
    std::cout << ans << "\n";

    std::sort(v.begin(), v.begin() + 5, cmp2);
    for (int i = 0; i < 5; ++i)
    {
        std::cout << v[i].first << " ";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}