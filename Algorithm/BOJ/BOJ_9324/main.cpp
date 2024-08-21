
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int main()
{
    FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        std::string s;
        std::cin >> s;
        bool ok = true;
        std::unordered_map<char, int> map;
        for (int i = 0; i < s.length(); ++i)
        {
            ++map[s[i]];
            if (map[s[i]] == 3)
            {
                if (i + 1 >= s.length() || s[i + 1] != s[i])
                {
                    ok = false;
                    break;
                }
                ++i;           // AAA가 나와서 AAAA가 됬으므로 네번쨰 A를 건너뜀
                map[s[i]] = 0; // AAAAA라서 이걸안비워주면 5번째 A검사할때 3번쨰나온건줄알고 또 처리함.
            }
        }

        std::cout << (ok ? "OK" : "FAKE") << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}