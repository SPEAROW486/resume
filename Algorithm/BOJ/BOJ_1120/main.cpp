
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string a, b;

int main()
{
    FASTIO;
    std::cin >> a >> b;

    int ans = INT_MAX;
    for (int i = 0; i <= b.length() - a.length(); ++i)
    {
        int cnt = 0;
        for (int j = 0; j < a.length(); ++j)
        {
            if (a[j] != b[j + i])
            {
                ++cnt;
            }
        }
        ans = std::min(ans, cnt);
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}