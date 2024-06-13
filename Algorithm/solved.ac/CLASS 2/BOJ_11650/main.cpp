
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> v;

#define X first
#define Y second

bool pred(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    int lx, ly;
    int rx, ry;

    std::tie(lx, ly) = lhs;
    std::tie(rx, ry) = rhs;
    if (lx == rx)
    {
        return ly < ry;
    }
    return lx < rx;
}

int main()
{
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
        std::cout << elem.X << " " << elem.Y << "\n";
    }

    return 0;
}