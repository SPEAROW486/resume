
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

bool solve(std::string s)
{
    bool contains = false;
    char prev = '\0';

    int mo = 0;
    int za = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            contains = true;
            za = 0;
            ++mo;
        }
        else
        {
            mo = 0;
            ++za;
        }

        if (prev != '\0')
        {
            std::string combine;
            combine.resize(2);
            combine[0] = prev;
            combine[1] = s[i];
            if (combine[0] == combine[1] && combine != "ee" && combine != "oo")
            {
                return false;
            }
        }

        if (mo >= 3 || za >= 3)
        {
            return false;
        }

        prev = s[i];
    }
    return true && contains;
}

int main()
{
    FASTIO;

    while (true)
    {
        std::string s;
        std::cin >> s;

        if (s == "end")
        {
            break;
        }

        if (solve(s))
        {
            std::cout << "<" << s << ">" << " is acceptable.\n";
        }
        else
        {
            std::cout << "<" << s << ">" << " is not acceptable.\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}