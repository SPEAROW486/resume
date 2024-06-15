
#include <bits/stdc++.h>

int r, c, n;

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> r >> c >> n;

    long long rn = r % n != 0 ? r / n + 1 : r / n;
    long long cn = c % n != 0 ? c / n + 1 : c / n;

    std::cout << rn * cn;

    int nn;
    std::cin >> nn;

    return 0;
}