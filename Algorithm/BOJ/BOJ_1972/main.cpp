
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

bool check(std::string s)
{
    int n = s.length();
    for (int i = 1; i < n; ++i)
    {
        int cnt = n - i;
        std::unordered_set<std::string> set;

        for (int j = 0; j < n - i; ++j)
        {
            std::string d;
            d += s[j];
            d += s[j + i];

            set.insert(d);
        }

        if (set.size() != cnt)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    FASTIO;

    std::string str;
    while (std::cin >> str)
    {
        if (str == "*")
        {
            break;
        }

        if (check(str))
        {
            std::cout << str << " is surprising.\n";
        }
        else
        {
            std::cout << str << " is NOT surprising.\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
