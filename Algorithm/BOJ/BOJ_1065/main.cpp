
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> s;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        s.push_back(i);
    }


    int ans = 0;
    for (int elem : s)
    {
        if (elem / 10 == 0 || elem / 10 < 10)
        {
            // 한 자릿수거나 두자릿수면
            ++ans;
        }
        else
        {
            int tmp = elem;
            int prev = -1;

            std::vector<int> digits;
            while (tmp > 0)
            {
                digits.push_back(tmp % 10);
                tmp /= 10;
            }

            int dist = digits[0] - digits[1];
            bool hansu = true;
            for (int i = 1; i < digits.size() - 1; ++i)
            {
                if (dist != (digits[i] - digits[i + 1]))
                {
                    hansu = false;
                }
            }

            if (hansu)
            {
                ++ans;
            }
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}