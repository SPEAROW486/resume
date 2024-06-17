
#include <bits/stdc++.h>

// 색, 위치
std::map<int, std::vector<int>> m;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int pos, color;
        std::cin >> pos >> color;

        m[color].push_back(pos);
    }

    long long length = 0;
    for (auto &elem : m)
    {
        std::vector<int> &v = elem.second;
        std::sort(v.begin(), v.end());

        if (v.size() == 1)
        {
            continue;
        }

        for (int i = 0; i < v.size(); ++i)
        {
            int left = i == 0 ? std::numeric_limits<int>::max() : v[i] - v[i - 1];
            int right = i == v.size() - 1 ? std::numeric_limits<int>::max() : v[i + 1] - v[i];

            length += std::min(left, right);
        }
    }

    std::cout << length;

    // int nn;
    // std::cin >> nn;

    return 0;
}