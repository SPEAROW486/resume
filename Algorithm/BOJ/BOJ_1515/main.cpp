
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;
int main()
{
    FASTIO;
    std::cin >> s;

    int idx = 0;
    int num = 1;
    while (idx != s.length())
    {
        std::string num_str = std::to_string(num++);
        for (int i = 0; i < num_str.length(); ++i)
        {
            if (s[idx] == num_str[i])
            {
                ++idx;
            }
        }
    }

    std::cout << num - 1 << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}