
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1001;
int d[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        d[i] = d[i - 1] % 10007 + d[i - 2] % 10007;
    }

    std::cout << d[n] % 10007;

    // int nn;
    // std::cin >> n;
    return 0;
}