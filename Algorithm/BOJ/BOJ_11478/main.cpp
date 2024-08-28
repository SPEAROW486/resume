
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

int main()
{
    FASTIO;
    std::cin >> s;

    std::unordered_set<std::string> set;

    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            std::string tmp;
            for (int k = j; k <= i; ++k)
            {
                tmp += s[k];
            }
            set.insert(tmp);
        }
    }

    std::cout << set.size() << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}