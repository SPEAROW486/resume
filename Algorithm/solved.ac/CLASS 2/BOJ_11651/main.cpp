
#include <bits/stdc++.h>

int n;

std::vector<std::pair<int, int>> v;

bool pred(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    if (lhs.second == rhs.second)
    {
        return lhs.first < rhs.first;
    }
    return lhs.second < rhs.second;
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        v.push_back({x, y});
    }

    std::sort(v.begin(), v.end(), pred);

    for (const auto &elem : v)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }

    return 0;
}