
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int NMAX = 101;
constexpr int INF = 1e9;
int n, m, r;

int items[101];

std::vector<std::vector<std::pair<int, int>>> graph(NMAX);

// 다익스트라로 시도 ㄱㄱ

std::vector<int> dijkstra(int st)
{
    std::vector<int> dist(NMAX, INF);
    dist[st] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, st});

    while (!pq.empty())
    {
        const std::pair<int, int> top = pq.top();
        pq.pop();

        const int weight = -top.first;
        const int vertex = top.second;

        if (dist[vertex] < weight)
        {
            continue;
        }

        const std::vector<std::pair<int, int>> &edge = graph[vertex];
        for (const std::pair<int, int> &e : edge)
        {
            const int &eWeight = e.first;
            const int &eVertex = e.second;

            const int via_weight = weight + eWeight;
            if (via_weight < dist[eVertex])
            {
                dist[eVertex] = via_weight;
                pq.push({-via_weight, eVertex});
            }
        }
    }

    return dist;
}

int main()
{
    FASTIO;
    std::cin >> n >> m >> r;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> items[i + 1];
    }

    for (int i = 0; i < r; ++i)
    {
        int st, en, wei;
        std::cin >> st >> en >> wei;
        graph[st].push_back({wei, en});
        graph[en].push_back({wei, st});
    }

    int ans = INT_MIN;
    for (int s = 1; s <= n; ++s)
    {
        std::vector<int> dist = dijkstra(s);
        int sum = 0;
        for (int i = 0; i < dist.size(); ++i)
        {
            if (dist[i] <= m)
            {
                sum += items[i];
            }
        }
        ans = std::max(ans, sum);
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}