
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int p;

int solve(int m)
{
    int length = 0;
    int p1 = 0;
    int p2 = 1;
    do
    {
        int tmp = p1;
        p1 = p2;
        p2 = (tmp + p2) % m;
        ++length;
    } while (p1 != 0 || p2 != 1);

    return length;
}
int main()
{
    // FASTIO;

    std::cin >> p;
    while (p--)
    {
        int n, m;
        std::cin >> n >> m;
        std::cout << n << " " << solve(m) << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}