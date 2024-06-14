
#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 1; i <= 9; ++i)
    {
        std::cout << n << " * " << i << " = " << n * i << "\n";
    }

    return 0;
}