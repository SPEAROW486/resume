
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    long long n;
    std::cin >> n;

    long long s = 0;
    long long t = 0;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        s += tmp;
    }

    t = n * (n - 1) / 2;

    std::cout << s - t << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}