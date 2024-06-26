
#include <bits/stdc++.h>

std::string s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> s;

    const char *delimiters = "-+";

    bool flag = false;
    int number = 0;
    std::string tmp;
    for (int i = 0; i <= s.size(); ++i)
    {
        if (s[i] == '+' || s[i] == '-' || i == s.size())
        {
            int t = std::stoi(tmp);
            if (flag)
            {
                number -= t;
            }
            else
            {
                number += t;
            }
            tmp.clear();
        }
        else
        {
            tmp += s[i];
        }

        if (s[i] == '-')
        {
            flag = true;
        }
    }

    std::cout << number;

    // int nn;
    // std::cin >> nn;
    return 0;
}