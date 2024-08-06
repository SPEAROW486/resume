
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    // FASTIO;
    std::cin >> n;

    std::set<std::string, std::greater<std::string>> set;
    for (int i = 0; i < n; ++i)
    {
        std::string name, log;
        std::cin >> name >> log;

        if (log == "enter")
        {
            set.insert(name);
        }
        else
        {
            set.erase(name);
        }
    }

    for (auto iter = set.begin(); iter != set.end(); ++iter)
    {
        std::cout << *iter << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}