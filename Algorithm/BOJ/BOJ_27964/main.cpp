
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::unordered_set<std::string> set;

int main()
{
    FASTIO;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;

        if (tmp.size() < 6)
        {
            continue;
        }

        if (tmp.substr(tmp.size() - 6) == "Cheese")
        {
            set.insert(tmp);
        }
    }

    std::cout << (set.size() >= 4 ? "yummy" : "sad") << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}