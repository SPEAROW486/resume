
#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int h, m;
    std::cin >> h >> m;

    h = h == 0 && m < 45 ? 24 : h;
    int total = h * 60 + m;

    total -= 45;

    std::cout << total / 60 << " " << total % 60;

    return 0;
}