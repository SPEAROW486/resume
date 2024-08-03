
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

std::vector<std::string> set = {
    "c=",
    "c-",
    "dz=",
    "d-",
    "lj",
    "nj",
    "s=",
    "z="};

int main()
{
    FASTIO;
    std::cin >> s;

    for (auto iter = set.begin(); iter != set.end(); ++iter)
    {
        const std::string str = *iter;
        while (true)
        {
            std::size_t idx = s.find(str);
            if (idx == std::string::npos)
            {
                break;
            }
            s.replace(idx, str.size(), "#");
        }
    }

    std::cout << s.size() << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}