
#include <bits/stdc++.h>

int n;

int main()
{
    int n;
    std::cin >> n;

    int cnt = 1;
    int temp = 1;
    int i = 1;
    while (n > 1)
    {
        ++cnt;
        temp = 6 * i;
        ++i;
        n -= temp;
    }

    std::cout << cnt;

    int nn;
    std::cin >> nn;

    return 0;
}