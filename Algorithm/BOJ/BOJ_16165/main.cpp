
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, std::string> map;                  // 멤버 : 소속 팀
    std::unordered_map<std::string, std::vector<std::string>> entries; // 팀 : 명단
    for (int i = 0; i < n; ++i)
    {
        std::string team;
        std::cin >> team;

        int cnt;
        std::cin >> cnt;
        for (int j = 0; j < cnt; ++j)
        {
            std::string name;
            std::cin >> name;

            map[name] = team;
            entries[team].push_back(name);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        std::string name;
        int type;
        std::cin >> name >> type;
        if (type == 0)
        {
            std::vector<std::string> &entry = entries[name];
            std::sort(entry.begin(), entry.end());
            for (const std::string &s : entry)
            {
                std::cout << s << "\n";
            }
        }
        else
        {
            std::cout << map[name] << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}