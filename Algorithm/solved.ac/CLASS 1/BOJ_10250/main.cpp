
#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        int h, w, n;
        std::cin >> h >> w >> n;

        int temp = 0;
        if (n % h == 0)
        {
            temp = h * 100 + (n / h);
        }
        else
        {
            temp = (n % h) * 100 + n / h + 1;
        }
        std::cout << temp << "\n";
    }

    return 0;
}