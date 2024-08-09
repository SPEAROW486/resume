
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    FASTIO;

    std::string s;
    std::cin >> s;

    int idx = s.find(":");
    int a = std::stoi(s.substr(0, idx));
    int b = std::stoi(s.substr(idx + 1));

    int g = gcd(a, b);

    a /= g;
    b /= g;

    std::cout << a << ":" << b << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}