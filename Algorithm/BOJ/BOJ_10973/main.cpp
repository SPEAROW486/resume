
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

void solve()
{
    if (std::prev_permutation(v.begin(), v.end()))
    {
        for (int i = 0; i < v.size(); ++i)
        {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "-1\n";
    }
}

int main()
{
    FASTIO;
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    solve();

    // int nn;
    // std::cin >> nn;
    return 0;
}