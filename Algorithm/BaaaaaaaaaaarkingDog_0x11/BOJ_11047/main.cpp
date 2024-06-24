
#include <bits/stdc++.h>

int n, k;
constexpr int MAX = 11;
int a[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    int count = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > k)
        {
            continue;
        }

        count += k / a[i];
        k %= a[i];
    }

    std::cout << count;

    // int nn;
    // std::cin >> nn;
    return 0;
}