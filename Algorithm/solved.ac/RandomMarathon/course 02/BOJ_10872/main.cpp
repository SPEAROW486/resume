
#include <bits/stdc++.h>

int n;

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    int fac = 1;
    for (int i = n; +i >= 1; --i)
    {
        fac *= i;
    }

    std::cout << fac;

    int nn;
    std::cin >> nn;

    return 0;
}