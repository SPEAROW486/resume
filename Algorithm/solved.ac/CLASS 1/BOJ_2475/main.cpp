
#include <bits/stdc++.h>

constexpr int MAX = 9;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1, n2, n3, n4, n5;
    std::cin >> n1 >> n2 >> n3 >> n4 >> n5;

    std::cout << (int)(pow(n1, 2) + pow(n2, 2) + pow(n3, 2) + pow(n4, 2) + pow(n5, 2)) % 10;
    return 0;
}