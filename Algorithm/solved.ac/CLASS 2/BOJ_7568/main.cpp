
#include <bits/stdc++.h>

int n;
constexpr int MAX = 51;

std::vector<std::pair<int, int>> v;

#define Weight first
#define Height second

int main()
{

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int w, h;
        std::cin >> w >> h;

        v.push_back({w, h});
    }

    for (int i = 0; i < n; ++i)
    {
        int order = 1;
        for (int j = 0; j < n; ++j)
        {
            if (v[i].Weight < v[j].Weight && v[i].Height < v[j].Height)
            {
                ++order;
            }
        }
        std::cout << order << " ";
    }

    return 0;
}