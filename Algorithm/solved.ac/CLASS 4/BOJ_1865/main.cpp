
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 501;
int n, m, w;

// start, end , weight
std::vector<std::tuple<int, int, int>> edges;
bool bellmanford(int start)
{
    std::vector<long long> dist(MAX);
    dist[start] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (const std::tuple<int, int, int> &e : edges)
        {
            int start, end, cost;
            std::tie(start, end, cost) = e;

            const long long via_cost = dist[start] + cost;
            if (via_cost < dist[end])
            {
                dist[end] = via_cost;
            }
        }
    }

    // 음수 사이클
    for (const std::tuple<int, int, int> &e : edges)
    {
        int start, end, cost;
        std::tie(start, end, cost) = e;

        const long long via_cost = dist[start] + cost;
        if (via_cost < dist[end])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    FASTIO;
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n >> m >> w;

        for (int i = 0; i < m; ++i)
        {
            int s, e, t;
            std::cin >> s >> e >> t;
            edges.emplace_back(s, e, t);
            edges.emplace_back(e, s, t);
        }

        for (int i = 0; i < w; ++i)
        {
            int s, e, t;
            std::cin >> s >> e >> t;
            edges.emplace_back(s, e, -t);
        }

        // 단 한번만 탐색해도 음수 사이클이 있는지 알 수 있으려면 단절되었다고 해도 건너뛰면 안됨.
        // (단절된 이후의 정점들 끼리에서 사이클이 존재할 수 있으므로)
        // 만약 모든 정점을 출발점으로 조사해서 cycle의 유무를 파악한다면 단절된곳은 건너뛰어도 어차피 다른 정점에서 다시 탐색할테니 괜찮음.
        std::cout << (bellmanford(1) ? "YES" : "NO") << "\n";

        edges.clear();
    }
    // int nn;
    // std::cin >> nn;
    return 0;
}