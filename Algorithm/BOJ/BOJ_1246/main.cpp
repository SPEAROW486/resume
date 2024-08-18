
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;

std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    int max = INT_MIN;
    int price = INT_MIN;
    for (int i = 0; i < v.size(); ++i)
    {
        int sum = v[i] * std::min(n, m - i);
        if (sum > max)
        {
            max = sum;
            price = v[i];
        }
    }

    std::cout << price << " " << max << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}