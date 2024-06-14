
#include <bits/stdc++.h>

int a, b, v;

int main()
{

    std::cin >> a >> b >> v;

    int result = std::ceil((double)(v - a) / (a - b));
    std::cout << result + 1;

    return 0;
}