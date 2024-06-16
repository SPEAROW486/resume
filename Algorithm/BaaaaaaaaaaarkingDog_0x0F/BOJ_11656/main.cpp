
#include <bits/stdc++.h>

constexpr int MAX = 1001;
std::string buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    buf[0] = s;
    for (int i = 1; i < s.length(); ++i)
    {
        buf[i] = s.substr(i, s.length());
    }

    std::sort(buf, buf + s.length());
    for (int i = 0; i <= s.length(); ++i)
    {
        std::cout << buf[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}