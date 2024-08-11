
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::string type;
std::unordered_set<std::string> set;
bool solve()
{
    int count = 0;
    if (type == "Y")
    {
        count = 1;
    }
    else if (type == "F")
    {
        count = 2;
    }
    else if (type == "O")
    {
        count = 3;
    }

    for (int i = 0; i < count; ++i)
    {
        if (set.empty())
        {
            return false;
        }
        set.erase(set.begin());
    }
    return true;
}

int main()
{
    FASTIO;

    std::cin >> n >> type;

    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        set.insert(tmp);
    }

    int ans = 0;
    while (true)
    {
        if (solve())
        {
            ++ans;
        }
        else
        {
            break;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}