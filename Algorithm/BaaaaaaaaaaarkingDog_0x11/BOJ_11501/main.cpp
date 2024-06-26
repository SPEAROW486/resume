
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1000001; // 1000001
int p[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> p[i];
        }

        int count = 0;
        long long buy = 0;
        int max = INT_MIN;
        for (int i = n; i >= 1; --i)
        {
            if (p[i] > max)
            {
                max = p[i];
            }
            else
            {
                buy += max - p[i];
            }
        }
        std::cout << buy << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}