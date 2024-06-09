
#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::getline(std::cin, s);

    int count = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            ++count;
        }
    }

    if (s[0] == ' ')
    {
        --count;
    }

    if (s[s.length() - 1] == ' ')
    {
        --count;
    }

    std::cout << count;

    return 0;
}