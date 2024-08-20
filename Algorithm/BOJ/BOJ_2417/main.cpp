#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

long long n;
long long q;
int main()
{
    FASTIO;

    std::cin >> n;

    q = sqrt(n);

    if (q * q < n)
    {
        ++q;
    }

    std::cout << q;

    // int nn;
    // std::cin >> nn;
    return 0;
}
