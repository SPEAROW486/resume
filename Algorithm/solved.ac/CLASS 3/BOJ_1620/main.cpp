
#include <bits/stdc++.h>

int n, m;

std::unordered_map<std::string, std::string> name_idx;
std::unordered_map<std::string, std::string> idx_name;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::string name;
        std::cin >> name;

        std::string idx = std::to_string(i);
        name_idx.insert({name, idx});
        idx_name.insert({idx, name});
    }

    for (int i = 0; i < m; ++i)
    {
        std::string cmd;
        std::cin >> cmd;

        if (std::all_of(cmd.begin(), cmd.end(), isdigit))
        {
            std::cout << idx_name[cmd] << "\n";
        }
        else
        {
            std::cout << name_idx[cmd] << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}