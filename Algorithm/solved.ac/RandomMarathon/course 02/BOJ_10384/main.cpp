
#include <bits/stdc++.h>

constexpr int MAX = 27;
int buf[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int n = 0;
    while (tc > n)
    {
        std::string s;
        std::getline(std::cin, s);

        for (int i = 0; i < s.length(); ++i)
        {
            if (!std::isalpha(s[i]))
            {
                continue;
            }

            int idx = std::isupper(s[i]) ? s[i] - 65 : s[i] - 97;
            ++buf[idx];
        }

        int pangram[3] = {0, 0, 0};
        for (int i = 0; i < MAX; ++i)
        {
            if (buf[i] > 2)
            {
                pangram[2]++;
            }
            if (buf[i] > 1)
            {
                pangram[1]++;
            }
            if (buf[i] > 0)
            {
                pangram[0]++;
            }
        }

        if (pangram[2] == 26)
        {
            std::cout << "Case " << n + 1 << ": " << "Triple pangram!!!\n";
        }
        else if (pangram[1] == 26)
        {
            std::cout << "Case " << n + 1 << ": " << "Double pangram!!\n";
        }
        else if (pangram[0] == 26)
        {
            std::cout << "Case " << n + 1 << ": " << "Pangram!\n";
        }
        else
        {
            std::cout << "Case " << n + 1 << ": " << "Not a pangram\n";
        }

        ++n;
        std::fill(buf, buf + MAX, 0);
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}