
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 501;
constexpr int EMAX = 6000;
constexpr int WEIGHT = 10000;
constexpr int INF = EMAX * WEIGHT * 2; // 간선의 개수는 최대 EMAX 최대 가중치는 WEIGHT이므로 한 경로의 최대 길이는 EMAX * WEIGHT 인데 더 넉넉하게줌.

// start , end , weight
std::vector<std::tuple<int, int, int>> edges(EMAX);
std::vector<long long> dist(MAX, INF);

int n, m;
bool bellmanford(int start)
{
    dist[start] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (const std::tuple<int, int, int> &e : edges)
        {
            int start, end, weight;
            std::tie(start, end, weight) = e;

            if (dist[start] == INF)
            {
                continue;
            }

            // 여기서 int면 언더플로우 날 수 있음.
            long long via_cost = dist[start] + weight;
            if (via_cost < dist[end])
            {
                dist[end] = via_cost;
            }
        }
    }

    // 위에서 벨만 포드 돌아서 최단경로를 구했는데
    // 아래서 한번 더 돌았을때 또 갱신이 가능하다면 음수<->음수 사이클이 있다는거네
    for (const std::tuple<int, int, int> &e : edges)
    {
        int start, end, weight;
        std::tie(start, end, weight) = e;

        if (dist[start] == INF)
        {
            continue;
        }

        // 여기서 int면 언더플로우 날 수 있음.
        long long via_cost = dist[start] + weight;
        if (via_cost < dist[end])
        {
            // 음수 사이클이 존재함
            return true;
        }
    }

    return false;
}

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        // edges를 미리 EMAX 만큼 잡아놨으니 emplace로
        edges.emplace_back(a, b, c);
    }

    // 음수 사이클이 존재하면 -1만 출력
    // 그렇지 않으면 2~N번까지 최단시간을 출력하되 경로가 없으면 -1
    bool negative = bellmanford(1);
    if (negative)
    {
        std::cout << -1 << "\n";
        return 0;
    }

    for (int i = 2; i <= n; ++i)
    {
        const int d = dist[i] >= INF ? -1 : dist[i];
        std::cout << d << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}