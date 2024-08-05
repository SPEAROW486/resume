
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int k, n;

int main()
{
    // FASTIO;
    std::cin >> k;

    for (int i = 0; i < k; ++i)
    {
        std::cin >> n;

        std::vector<int> v;
        for (int j = 0; j < n; ++j)
        {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);
        }

        std::sort(v.begin(), v.end());
        int gap = INT_MIN;
        for (int i = v.size() - 1; i > 0; --i)
        {
            gap = std::max(gap, v[i] - v[i - 1]);
        }
        std::cout << "Class " << i + 1 << "\n";
        std::cout << "Max " << v[v.size() - 1] << ", " << "Min " << v[0] << ", " << "Largest gap " << gap << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}