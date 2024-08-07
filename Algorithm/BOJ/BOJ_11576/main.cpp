
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int a, b;
int m;

int main()
{
    FASTIO;
    std::cin >> a >> b;
    std::cin >> m;

    int n = 0;
    while (m--)
    {
        int tmp;
        std::cin >> tmp;
        n += tmp * pow(a, m);
    }

    std::stack<int> s;
    while (n > 0)
    {
        s.push(n % b);
        n /= b;
    }

    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}