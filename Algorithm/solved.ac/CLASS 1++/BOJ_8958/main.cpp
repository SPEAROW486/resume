
#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    while (tc--)
    {

        std::string s;
        std::cin >> s;

        int score = 0;
        int cnt = 1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'O')
            {
                score += cnt;
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
        }

        std::cout << score << "\n";
    }
    return 0;
}