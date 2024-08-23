
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int main()
{
    // FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end(), std::greater<>());

    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if ((i + 1) % 3 == 0)
        {
            continue;
        }

        ans += v[i];
    }

    std::cout << ans << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}