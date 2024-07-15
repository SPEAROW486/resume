
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    int n;
    std::cin >> n;
    std::vector<std::string> vec(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());

    int prefix_count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (vec[j].substr(0, vec[i].size()) == vec[i])
            {
                ++prefix_count;
                break;
            }
        }
    }

    std::cout << n - prefix_count;

    // int nnn;
    // std::cin >> nnn;
    return 0;
}