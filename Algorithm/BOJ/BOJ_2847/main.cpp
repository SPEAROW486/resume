
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

    int total = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        if (v[i - 1] >= v[i])
        {
            int decrease = v[i - 1] - (v[i] - 1);
            total += decrease;
            v[i - 1] -= decrease;
        }
    }

    std::cout << total;

    // int nn;
    // std::cin >> nn;
    return 0;
}
