
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;
int n, m;

int main()
{
    // FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        std::cin >> n;
        std::unordered_set<int> set1;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            set1.insert(tmp);
        }

        std::cin >> m;
        std::vector<int> v;
        for (int i = 0; i < m; ++i)
        {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);
        }

        for (auto it : v)
        {
            if (set1.find(it) != set1.end())
            {
                std::cout << "1\n";
            }
            else
            {
                std::cout << "0\n";
            }
        }
    }

    return 0;
}