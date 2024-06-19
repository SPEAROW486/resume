
#include <bits/stdc++.h>

int n;
constexpr int MAX = 41;
int p[MAX][2];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    p[0][0] = 1;
    p[1][1] = 1;
    for (int i = 2; i <= 40; ++i)
    {
        p[i][0] = p[i - 1][0] + p[i - 2][0];
        p[i][1] = p[i - 1][1] + p[i - 2][1];
    }

    int tc;
    std::cin >> tc;
    while (tc--)
    {
        std::cin >> n;
        std::cout << p[n][0] << " " << p[n][1] << "\n";
    }

    // int nn;
    // std::cin >> n;
    return 0;
}