
#include <bits/stdc++.h>

constexpr int MAX = 500001;
int n, m;

int card[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> card[i];
    }

    std::cin >> m;
    std::sort(card, card + n);

    for (int i = 0; i < m; ++i)
    {
        int temp;
        std::cin >> temp;

        std::cout << std::upper_bound(card, card + n, temp) - std::lower_bound(card, card + n, temp) << " ";
    }

    return 0;
}