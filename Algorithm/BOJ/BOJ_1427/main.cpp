
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

    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }

    std::sort(v.begin(), v.end(), std::greater<int>());

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}