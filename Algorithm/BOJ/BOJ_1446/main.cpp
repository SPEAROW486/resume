#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

using ll = long long;

// BOJ : 1446

int main()
{
    FASTIO;

    int n, d;
    std::cin >> n >> d;

    std::vector<std::pair<int, int>> adj[10001]; // 인접 리스트 (지름길의 정보)
    for (int i = 0; i < n; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (v <= d && v - u > w)
        {
            adj[u].emplace_back(v, w); // 지름길 정보 저장
        }
    }

    std::vector<int> dist(d + 1); // 최소 거리 저장
    for (int i = 0; i <= d; ++i)
    {
        dist[i] = i; // 초기 거리는 i
    }

    for (int i = 0; i <= d; ++i)
    {
        if (i > 0)
        {
            dist[i] = std::min(dist[i], dist[i - 1] + 1); // 1칸 이동하는 경우
        }
        for (auto &p : adj[i])
        {
            int next = p.first;
            int cost = p.second;
            dist[next] = std::min(dist[next], dist[i] + cost); // 지름길 사용하는 경우
        }
    }

    std::cout << dist[d] << '\n'; // 최종 목적지까지의 최소 거리 출력

    return 0;
}
