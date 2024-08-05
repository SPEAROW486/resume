
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001;
int a, b, n;

int main()
{
    // FASTIO;
    std::cin >> a >> b;
    std::cin >> n;

    int min = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        std::cin >> tmp;

        min = std::min(min, abs(tmp - b) + 1);
    }

    std::cout << std::min(abs(a - b), min);

    // int nn;
    // std::cin >> nn;
    return 0;
}