
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
int main()
{
    //    FASTIO;

    std::cin >> n >> m;

    std::unordered_set<std::string> set;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        set.insert(s);
    }

    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        std::string s;
        std::cin >> s;

        if (set.find(s) != set.end())
        {
            ++ans;
        }
    }

    std::cout << ans;

    int nn;
    std::cin >> nn;

    return 0;
}