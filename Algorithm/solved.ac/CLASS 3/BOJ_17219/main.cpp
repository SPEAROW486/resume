
#include <bits/stdc++.h>

int n, m;
std::unordered_map<std::string, std::string> map;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::string site, pw;
        std::cin >> site >> pw;

        map[site] = pw;
    }

    for (int i = 0; i < m; ++i)
    {
        std::string site;
        std::cin >> site;

        std::cout << map[site] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}