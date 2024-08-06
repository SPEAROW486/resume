
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
std::vector<int> v;

int main()
{
    FASTIO;

    int n;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;

        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    std::cout << v[k - 1] << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
