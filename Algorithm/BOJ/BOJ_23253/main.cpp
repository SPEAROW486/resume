
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 200001;
int dum[MAX];
int n, m;

std::priority_queue<std::tuple<int, int, int>> pq;
int main()
{
    FASTIO;

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int k;
        std::cin >> k;
        for (int j = k - 1; j >= 0; --j)
        {
            int tmp;
            std::cin >> tmp;
            pq.push({-tmp, i, j});
        }
    }

    while (!pq.empty())
    {
        int number, dummy, order;
        std::tie(number, dummy, order) = pq.top();
        pq.pop();

        if (dum[dummy]++ != order)
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}