
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string n;

int get_parts_count(std::string s, char number)
{
    int count = 0;

    std::vector<std::string> parts;
    std::string p;
    for (int i = 0; i <= s.length(); ++i)
    {
        if (s[i] != number || i == s.length())
        {
            if (!p.empty())
            {
                parts.push_back(p);
                p.clear();
            }
            continue;
        }
        p += s[i];
    }

    return parts.size();
}

int main()
{
    FASTIO;
    std::cin >> n;

    int part_0 = get_parts_count(n, '0');
    int part_1 = get_parts_count(n, '1');

    // 처음부터 단일 파츠라 뒤집을 필요가 없을 경우
    if (part_0 == n.size() || part_1 == n.size())
    {
        std::cout << "0\n";
    }
    else
    {
        std::cout << std::min(part_0, part_1) << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}