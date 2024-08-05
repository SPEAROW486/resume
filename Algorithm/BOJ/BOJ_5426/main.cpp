
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string solve(std::string s)
{
    int length = sqrt(s.length());
    std::vector<std::string> v;

    int idx = 0;
    for (int i = 0; i < length; ++i)
    {
        std::string sub = s.substr(idx, length);
        idx += length;

        v.push_back(sub);
    }

    std::vector<std::string> v2(v);
    std::string ans;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int idx = v[i].size() - 1 - i;
            v2[i][j] = v[j][idx];
        }
        ans += v2[i];
    }

    return ans;
}

int main()
{
    FASTIO;
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::string s;
        std::cin >> s;
        std::cout << solve(s) << "\n";
    };

    // int nn;
    // std::cin >> nn;
    return 0;
}