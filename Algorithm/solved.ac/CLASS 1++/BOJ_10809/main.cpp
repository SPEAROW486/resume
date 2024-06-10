
#include <bits/stdc++.h>

int buf[26];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    std::fill(buf, buf + 26, -1);
    for (int i = 0; i < s.length(); ++i)
    {
        if (buf[s[i] - 97] == -1)
        {
            buf[s[i] - 97] = i;
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        std::cout << buf[i] << " ";
    }

    return 0;
}