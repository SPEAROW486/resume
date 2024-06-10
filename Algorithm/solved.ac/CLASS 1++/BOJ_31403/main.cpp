
#include <bits/stdc++.h>

int main()
{
    int a, b, c;

    std::cin >> a >> b >> c;
    std::cout << a + b - c << "\n";

    std::string s = std::to_string(a) + std::to_string(b);
    int si = std::stoi(s);

    std::cout << si - c;

    return 0;
}