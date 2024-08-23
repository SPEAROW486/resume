
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

    set.insert("ChongChong");
    for (int i = 0; i < n; ++i)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;

        auto it1 = set.find(str1);
        auto it2 = set.find(str2);

        if (it1 != set.end() || it2 != set.end())
        {
            // 둘 중한명이라도 명단에 있다면
            set.insert(str1);
            set.insert(str2);
        }
    }

    std::cout << set.size();

    int nn;
    std::cin >> nn;
    return 0;
}