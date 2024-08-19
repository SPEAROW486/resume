
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::string> v;
bool is_cycle(const std::string &s)
{
    int length = s.length();

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].length() != length)
        {
            continue;
        }

        std::string tmp = v[i] + v[i];
        if (tmp.find(s) != std::string::npos)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        if (!is_cycle(tmp))
        {
            v.push_back(tmp);
        }
    }

    std::cout << v.size();

    // int nn;
    // std::cin >> nn;
    return 0;
}