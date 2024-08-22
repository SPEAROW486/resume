
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;

    std::cin >> n;
    std::unordered_map<std::string, int> entry;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        ++entry[tmp];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        --entry[tmp];
    }

    for (const auto &iter : entry)
    {
        if (iter.second != 0)
        {
            std::cout << iter.first << "\n";
            break;
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}