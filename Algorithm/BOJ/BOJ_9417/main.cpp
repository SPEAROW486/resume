
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    // FASTIO;

    std::cin >> tc;
    std::cin.ignore();
    while (tc--)
    {
        std::string s;
        std::getline(std::cin, s);

        int pos = 0;
        int idx = 0;
        std::vector<int> v;
        while (idx != std::string::npos)
        {
            idx = s.find(" ", pos);
            std::string str = s.substr(pos, idx - pos);
            v.push_back(std::stoi(str));
            pos = idx + 1;
        }

        int max = INT_MIN;
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                max = std::max(max, gcd(v[i], v[j]));
            }
        }

        std::cout << max << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}