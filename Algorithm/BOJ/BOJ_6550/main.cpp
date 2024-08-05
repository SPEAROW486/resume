
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

bool solve(const std::string &s1, const std::string &s2)
{
    int pos = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        int idx = s2.find(s1[i], pos);
        if (idx == std::string::npos)
        {
            return false;
        }
        pos = idx;
    }
    return true;
}

int main()
{
    // FASTIO;
    std::string s1, s2;
    while (std::cin >> s1 >> s2)
    {

        int idx = 0;
        for (int i = 0; i < s2.length(); ++i)
        {
            if (s1[idx] == s2[i])
            {
                ++idx;
            }
        }

        if (idx == s1.size())
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    int nn;
    std::cin >> nn;
    return 0;
}