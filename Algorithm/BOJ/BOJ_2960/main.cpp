
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
std::vector<bool> v;
int main()
{
    FASTIO;
    std::cin >> n >> k;
    v.resize(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        v[i] = true;
    }

    int cnt = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (v[i])
        {
            v[i] = false;
            ++cnt;
            if (cnt == k)
            {
                std::cout << i << "\n";
            }
        }

        for (int j = i * i; j <= n; j += i)
        {
            if (v[j])
            {
                v[j] = false;
                ++cnt;
                if (cnt == k)
                {
                    std::cout << j << "\n";
                }
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}