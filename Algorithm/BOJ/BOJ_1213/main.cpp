
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;
std::map<char, int> map;

int main()
{
    FASTIO;

    std::cin >> s;
    std::string tmp(s.length(), '?');

    for (int i = 0; i < s.length(); ++i)
    {
        ++map[s[i]];
    }

    int lidx = 0;
    int ridx = s.length() - 1;
    for (auto iter : map)
    {
        const char c = iter.first;
        if (iter.second >= 2)
        {
            for (int i = 0; i < iter.second / 2; ++i)
            {
                tmp[lidx++] = c;
                tmp[ridx--] = c;
                map[c] -= 2;
            }
        }
    }

    if (s.length() % 2 != 0)
    {
        // 홀수면 중간 인덱스에 삽입
        int midx = s.length() / 2;
        for (auto iter : map)
        {
            const char c = iter.first;
            if (iter.second > 0)
            {
                tmp[midx] = c;
                break;
            }
        }
    }

    bool can = tmp.find('?') == std::string::npos;
    if (can)
    {
        std::cout << tmp << "\n";
    }
    else
    {
        std::cout << "I'm Sorry Hansoo\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}