
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 100001; // 100001;
constexpr int NMAX = 101;
constexpr int INF = 1e9;

int n, m;
int dist[NMAX][NMAX];

int main()
{
    FASTIO;
    //  int tc;
    //  std::cin >> tc;

    std::cin >> n;
    std::cin >> m;
    std::fill(&dist[0][0], &dist[NMAX - 1][NMAX], INF);
    for (int i = 0; i < m; ++i)
    {
        int st, en, wei;
        std::cin >> st >> en >> wei;
        dist[st][en] = std::min(dist[st][en], wei);
    }

    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k) // 경유
    {
        for (int i = 1; i <= n; ++i) // 출발
        {
            for (int j = 1; j <= n; ++j) // 도착
            {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] >= INF)
            {
                std::cout << "0 ";
            }
            else
            {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}