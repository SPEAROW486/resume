
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    long long ans = 0;
    std::sort(v.begin(), v.end(), std::greater<>());
    for (int i = 0; i < v.size(); ++i)
    {
        int tip = std::max(v[i] - i, 0);
        ans += tip;
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}