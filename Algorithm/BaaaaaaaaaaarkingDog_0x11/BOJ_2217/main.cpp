
#include <bits/stdc++.h>

constexpr int MAX = 100001;
int n;
int r[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> r[i];
    }

    std::sort(r, r + n);

    int max_weight = INT_MIN;
    for (int k = 1; k <= n; ++k)
    {
        max_weight = std::max(max_weight, r[n - k] * k);
    }

    std::cout << max_weight;

    return 0;
}