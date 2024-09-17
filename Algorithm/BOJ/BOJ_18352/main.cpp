#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 18352

constexpr int MAX = 300001;
constexpr int INF = 1e9;
int dist[MAX];

std::vector<std::vector<std::pair<int, int>>> vec;

std::vector<int> ans;
int n, m, k, x;

void dijkstra(int start)
{
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        std::pair<int, int> top = pq.top();
        const int cost = -top.first;
        const int node = top.second;
        pq.pop();

        if (dist[node] < cost)
        {
            continue;
        }

        const std::vector<std::pair<int, int>> edges = vec[node];
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

    std::cin >> n >> m >> k >> x;

    // 1-based index
    vec.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        // 단방향이고 비용은 1로 고정
        vec[st].push_back({1, en});
    }

    dijkstra(x);

    // k 거리에 있는 도시들 찾기
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == k)
        {
            ans.push_back(i);
        }
    }

    if (ans.size() == 0)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::sort(ans.begin(), ans.end());
        for (const int a : ans)
        {
            std::cout << a << "\n";
        }
    }
    // int nn;
    // std::cin >> nn;
    return 0;
}
