
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 51;
constexpr int INF = 10000000;
int dist[MAX][MAX];

int n;

void dump()
{
    std::cout << "\n\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    // FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        for (int j = 0; j < s.length(); ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = s[j] == 'Y' ? 1 : INF;
            }
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 2-친구라
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            // 건너건너는안되고 한 다리만 건너서 친구일때만 세야하므로 INF보다 작은게 아니라 2로 비교했어야..
            if (dist[i][j] > 0 && dist[i][j] <= 2)
            {
                ++cnt;
            }
        }
        max = std::max(max, cnt);
    }

    std::cout << max;

    return 0;
}