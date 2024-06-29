
#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    while (tc--)
    {
        int n;
        std::cin >> n;
        std::unordered_map<std::string, int> map;
        for (int i = 0; i < n; ++i)
        {
            std::string name, category;
            std::cin >> name >> category;

            map[category]++;
        }

        int ans = 1;
        for (const auto &elem : map)
        {
            ans *= elem.second + 1;
        }
        ans -= 1;

        std::cout << ans << "\n";
    }

    return 0;
}
