
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc, n;

bool solve(const std::string &s)
{
    int lidx = 0;
    int ridx = s.size() - 1;

    for (int j = 0; j < s.size() / 2; ++j)
    {
        if (s[lidx] != s[ridx])
        {
            return false;
        }
        ++lidx;
        --ridx;
    }
    return true;
}

int main()
{
    FASTIO;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n;

        std::vector<std::string> v;
        for (int i = 0; i < n; ++i)
        {
            std::string tmp;
            std::cin >> tmp;

            v.push_back(tmp);
        }

        std::vector<std::string> candidates;
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v.size(); ++j)
            {
                if (i == j)
                {
                    continue;
                }

                candidates.push_back(v[i] + v[j]);
            }
        }

        std::string ans = "0";
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (solve(candidates[i]))
            {
                ans = candidates[i];
                break;
            }
        }

        std::cout << ans << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}