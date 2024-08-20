#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
int m;
constexpr int MAX = 201;
bool check[MAX][MAX];
int main()
{
    FASTIO;

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;

        check[tmp1][tmp2] = check[tmp2][tmp1] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n - 2; ++i)
    {
        for (int j = i + 1; j <= n - 1; ++j)
        {
            for (int k = j + 1; k <= n; ++k)
            {
                if (check[i][j] || check[j][k] || check[i][k])
                {
                    continue;
                }
                ++ans;
            }
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}
