
#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        int n;
        std::string s;
        std::cin >> n >> s;

        std::string p;

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                p += s[i];
            }
        }

        std::cout << p << "\n";
    }

    return 0;
}