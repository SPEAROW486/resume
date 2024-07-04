
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 20001;
constexpr int EMAX = 300001;
constexpr int WEIGHT = 10;
constexpr int INF = EMAX * WEIGHT * 2; // 간선의 개수는 최대 300,000 최대 가중치는 10이므로 한 경로의 최대 길이는 2개의 곱인데 더 넉넉하게줌.

std::vector<std::vector<std::pair<int, int>>> nodes(MAX);
std::priority_queue<std::pair<int, int>> pq;
int dist[MAX];

void dijkstra(int start)
{
    std::fill(dist, dist + MAX, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        const std::pair<int, int> top = pq.top();
        pq.pop();

        const int cost = -top.first;
        const int node = top.second;

        if (dist[node] < cost)
        {
            continue;
        }

        const std::vector<std::pair<int, int>> &edges = nodes[node];
        for (const std::pair<int, int> &e : edges)
        {
            const int eCost = e.first;
            const int eNode = e.second;

            const int via_cost = cost + eCost;

            if (via_cost < dist[eNode])
            {
                dist[eNode] = via_cost;
                pq.push({-via_cost, eNode});
            }
        }
    }
}

int main()
{
    FASTIO;
    int v, e;
    std::cin >> v >> e;

    int st;
    std::cin >> st;

    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        nodes[u].push_back({w, v});
    }

    dijkstra(st);

    for (int i = 1; i <= v; ++i)
    {
        if (dist[i] >= INF)
        {
            std::cout << "INF\n";
        }
        else
        {
            std::cout << dist[i] << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}