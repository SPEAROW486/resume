
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int INF = 1e9;
int n, m;

std::vector<std::vector<std::pair<int, int>>> edges;
std::vector<int> dist;
std::vector<int> paths;

void dijkstra(int st)
{
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

        const std::vector<std::pair<int, int>> &ed = edges[vertex];
        for (const std::pair<int, int> &next : ed)
        {
            const int &nWeight = next.first;
            const int &nVertex = next.second;

            const int via_weight = weight + nWeight;
            if (via_weight < dist[nVertex])
            {
                dist[nVertex] = via_weight;
                pq.push({-via_weight, nVertex});
                paths[nVertex] = vertex;
            }
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n;
    std::cin >> m;

    dist.resize(n + 1, INF);
    paths.resize(n + 1, 0);
    edges.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int st, en, wei;
        std::cin >> st >> en >> wei;
        edges[st].push_back({wei, en});
    }

    int st, en;
    std::cin >> st >> en;
    dijkstra(st);

    std::cout << dist[en] << "\n";
    std::vector<int> v;
    int tmp = en;
    while (tmp != 0)
    {
        v.push_back(tmp);
        tmp = paths[tmp];
    }

    std::cout << v.size() << "\n";
    for (int i = v.size() - 1; i >= 0; --i)
    {
        std::cout << v[i] << " ";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}