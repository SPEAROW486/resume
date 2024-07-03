
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 801; // 801;
constexpr int INF = 1e9; // 정점의 최대 개수 x 가중치의 최대 크기에 따라서 생각보다 큰 값으로 잡아줘야함.
                         // 여기서는 800 x 1000해서 최악의 경우 경로 1개의 길이가 800,000이 될 수 있으므로 실제 경로가 존재하는데 INF가 1e6 (1,000,000)이라면 경로가 없다고 판단해버릴 수 있음.
std::vector<std::vector<std::pair<int, int>>> nodes(MAX);
std::priority_queue<std::pair<int, int>> pq;

int u, v;
void dijkstra(int start, std::vector<int> &dist)
{
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
    int n, e;
    std::cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int st, en, cost;
        std::cin >> st >> en >> cost;
        nodes[st].push_back({cost, en});
        nodes[en].push_back({cost, st});
    }

    std::cin >> u >> v;

    std::vector<int> dist_from_one(MAX, INF);
    std::vector<int> dist_from_u(MAX, INF);
    std::vector<int> dist_from_v(MAX, INF);

    dijkstra(1, dist_from_one);
    dijkstra(u, dist_from_u);
    dijkstra(v, dist_from_v);

    int path1 = dist_from_one[u] + dist_from_u[v] + dist_from_v[n];
    int path2 = dist_from_one[v] + dist_from_v[u] + dist_from_u[n];

    if (dist_from_one[u] == INF || dist_from_u[v] == INF || dist_from_v[n] == INF)
    {
        path1 = INF;
    }
    if (dist_from_one[v] == INF || dist_from_v[u] == INF || dist_from_u[n] == INF)
    {
        path2 = INF;
    }

    int ans = std::min(path1, path2);
    ans = (ans >= INF) ? -1 : ans;
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}