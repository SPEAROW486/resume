
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int NMAX = 1001;  // 1001;
constexpr int MAX = 100001; // 100001;
constexpr int INF = 1e9;

int n, m;

// weight, vertex
std::vector<std::vector<std::pair<int, int>>> edges(MAX);
std::priority_queue<std::pair<int, int>> pq;

std::vector<int> dist(NMAX, INF);

void dijkstra(int st)
{
    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty())
    {
        const std::pair<int, int> top = pq.top();
        pq.pop();

        const int weight = -top.first;
        const int vertex = top.second;

        // 이미 최단 경로
        if (dist[vertex] < weight)
        {
            continue;
        }

        const std::vector<std::pair<int, int>> &e = edges[vertex];
        for (const std::pair<int, int> &element : e)
        {
            const int eWeight = element.first;
            const int eVertex = element.second;

            const int via_weight = weight + eWeight;
            if (via_weight < dist[eVertex])
            {
                dist[eVertex] = via_weight;
                pq.push({-via_weight, eVertex});
            }
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n;
    std::cin >> m;

    for (int i = 0; i < m; ++i)
    {
        int s, e, w;
        std::cin >> s >> e >> w;

        edges[s].push_back({w, e});
    }

    int st, en;
    std::cin >> st >> en;

    dijkstra(st);
    std::cout << dist[en];

    // int nn;
    // std::cin >> nn;

    return 0;
}