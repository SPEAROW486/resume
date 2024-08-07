
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    // FASTIO;

    std::string s, t;
    std::cin >> s >> t;

    std::string str1;
    std::string str2;

    for (int i = 0; i < t.length(); ++i)
    {
        str1 += s;
    }

    for (int i = 0; i < s.length(); ++i)
    {
        str2 += t;
    }

    if (str1 == str2)
    {
        std::cout << "1\n";
    }
    else
    {
        std::cout << "0\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}