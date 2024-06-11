
#include <bits/stdc++.h>

int n;

std::vector<std::string> v;
bool cmp(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
    {
        return s1.length() < s2.length();
    }
    else
    {
        return s1 < s2;
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        if (std::find(v.begin(), v.end(), s) == v.end())
        {
            v.push_back(s);
        }
    }

    std::sort(v.begin(), v.end(), cmp);

    for (std::string s : v)
    {
        std::cout << s << "\n";
    }

    return 0;
}