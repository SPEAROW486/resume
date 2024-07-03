
#include <bits/stdc++.h>

constexpr int n = 3;          // 노드의 개수는 3개로 설정
constexpr int INF = 10000000; // 그냥 적당히 큰값 ㅇㅇ 오버플로우 안날만한
int dist[n];                  // 시작점부터 각 노드까지의 비용 배열이니까 N개 만큼.

// 기본이 최대힙(내림차순)이고, pair를 쓰면 first -> second 순으로 비교함, 근데 최소힙을 써야하는데 pq를 최소힙 형태로 선언하면 너무 기니까 값을 음수로 처리
// pair는 비용, 노드가 됨.

std::vector<std::vector<std::pair<int, int>>> vec(n);
void dijkstra(int start)
{
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        const std::pair<int, int> top = pq.top();
        const int cost = -top.first;
        const int node = top.second;

        pq.pop();
        // 방문 하지 않은 노드는 INF로 채워져있으니
        // 방문 했다는건 이미 최단경로를 안다는것
        if (dist[node] < cost)
        {
            continue;
        }

        // 모든 인접 노드
        const std::vector<std::pair<int, int>> &edges = vec[node];
        for (const std::pair<int, int> &e : edges)
        {
            // self = node
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
    // FASTIO;

    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
    }

    vec[0].push_back({5, 1}); // 0->1 비용 5
    vec[0].push_back({1, 2}); // 0->2 비용 1
    vec[2].push_back({3, 1}); // 2->1 비용 3

    // 그냥 새로 배우는거니까 0번 노드를 시작점으로
    dijkstra(0);

    // 0번노드에서부터 n-1번까지 가는 최소 비용들
    for (int i = 0; i < n; ++i)
    {
        std::cout << dist[i] << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}