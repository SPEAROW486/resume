
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::map<std::string, int> map;

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        ++map[tmp];
    }

    int max = INT_MIN;
    std::string ans;
    for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        if (iter->second > max)
        {
            ans = iter->first;
            max = iter->second;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}