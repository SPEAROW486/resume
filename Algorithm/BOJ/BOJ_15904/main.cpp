
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;
bool solve()
{
    int found[26] = {
        0,
    };

    char a[4] = {'U', 'C', 'P', 'C'};

    int pos = 0;
    int idx = 0;
    for (int i = 0; i < 4; ++i)
    {
        idx = s.find(a[i], pos);
        if (idx != std::string::npos)
        {
            pos = idx;
            ++found[a[i] - 'A'];
        }
    }

    return found[a[0] - 'A'] > 0 && found[a[1] - 'A'] > 1 && found[a[2] - 'A'] > 0;
}

int main()
{
    FASTIO;

    std::getline(std::cin, s);
    if (solve())
    {
        std::cout << "I love UCPC\n";
    }
    else
    {
        std::cout << "I hate UCPC\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}