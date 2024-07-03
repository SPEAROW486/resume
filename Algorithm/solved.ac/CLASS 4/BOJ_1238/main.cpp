
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int INF = 10000000;
constexpr int MAX = 1001;
int n, m, x;

// cost, node
std::priority_queue<std::pair<int, int>> pq;
std::vector<std::vector<std::pair<int, int>>> nodes(MAX);

int dist[MAX];
int buf[MAX][MAX];

void dijkstra(int start)
{
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        const std::pair<int, int> top = pq.top();
        const int cost = -top.first;
        const int node = top.second;
        pq.pop();

        if (dist[node] < cost)
        {
            continue;
        }

        // 현재 노드의 간선
        const std::vector<std::pair<int, int>> &edges = nodes[node];
        for (const std::pair<int, int> &e : edges)
        {
            int eCost = e.first;
            int eNode = e.second;
            int via_cost = cost + eCost;

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

    std::cin >> n >> m >> x;

    for (int i = 0; i < m; ++i)
    {
        int st, en, cost;
        std::cin >> st >> en >> cost;

        // pq에서 cost / en으로 쓸거니까 벡터도 동일하게
        nodes[st].push_back({cost, en});
    }

    int max = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        std::fill(dist, dist + n + 1, INF);

        // i부터 나머지 정점까지 가는 최단경로를 모두 기록
        dijkstra(i);
        for (int j = 1; j <= n; ++j)
        {
            buf[i][j] = dist[j];
        }
    }

    // 합산
    for (int i = 1; i <= n; ++i)
    {
        if (i == x)
        {
            continue;
        }
        buf[x][i] += buf[i][x];
    }

    std::cout << *std::max_element(buf[x], buf[x] + n + 1);

    // int nn;
    // std::cin >> nn;
    return 0;
}
