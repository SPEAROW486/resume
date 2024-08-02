
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 101;
bool board[MAX][MAX];
int n, m, k;

int main()
{
    FASTIO;
    std::cin >> n >> m;

    std::vector<int> horizon_separation = {0, m};
    std::vector<int> vertical_separation = {0, n};

    std::cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int type, number;
        std::cin >> type >> number;

        if (type == 0)
        {
            horizon_separation.push_back(number);
        }
        else
        {
            vertical_separation.push_back(number);
        }
    }

    std::sort(horizon_separation.begin(), horizon_separation.end());
    std::sort(vertical_separation.begin(), vertical_separation.end());

    int max_horizon = 0;
    for (int i = 1; i < horizon_separation.size(); ++i)
    {
        int dist = horizon_separation[i] - horizon_separation[i - 1];
        max_horizon = std::max(max_horizon, dist);
    }

    int max_vertical = 0;
    for (int i = 1; i < vertical_separation.size(); ++i)
    {
        int dist = vertical_separation[i] - vertical_separation[i - 1];
        max_vertical = std::max(max_vertical, dist);
    }

    std::cout << max_horizon * max_vertical;

    // int nn;
    // std::cin >> nn;
    return 0;
}