#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 20291
// 문자열 파싱, 트리 맵 문제인듯
int n;
std::map<std::string, int> map;

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        auto idx = s.find('.');
        std::string ext = s.substr(idx + 1);
        ++map[ext];
    }

    for (const auto &e : map)
    {
        std::cout << e.first << " " << e.second << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
