
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::set<std::string> set;

int main()
{
    // FASTIO;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "ENTER")
        {
            ans += set.size();
            set.clear();
        }
        else
        {
            set.insert(cmd);
        }
    }

    std::cout << ans + set.size();

    int nn;
    std::cin >> nn;
    return 0;
}