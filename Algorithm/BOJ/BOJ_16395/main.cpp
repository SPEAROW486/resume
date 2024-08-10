
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
int solve()
{
    std::vector<int> v = {1};
    for (int i = 2; i <= n; ++i)
    {
        std::vector<int> next;
        next.resize(i);
        for (int j = 0; j < next.size(); ++j)
        {
            if (j == 0 || j == next.size() - 1)
            {
                next[j] = 1;
            }
            else
            {
                // 이전 행의 j-1 항과 j항을 더해서
                next[j] = v[j - 1] + v[j];
            }
        }
        v = next;
    }

    return v[k - 1];
}

int main()
{
    FASTIO;

    std::cin >> n >> k;
    std::cout << solve() << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}