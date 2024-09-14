#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14496
// BFS

// BFS 탐색 함수
int bfs(int start, int end, const std::vector<std::vector<int>> &adj)
{
    std::vector<int> dist(adj.size(), -1); // 거리 저장, -1은 아직 방문하지 않았음을 의미
    std::queue<int> q;

    dist[start] = 0; // 시작 노드는 거리가 0
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // 현재 노드와 연결된 노드들 확인
        for (int next : adj[current])
        {
            if (dist[next] == -1)
            {                                   // 아직 방문하지 않은 노드라면
                dist[next] = dist[current] + 1; // 거리를 갱신
                q.push(next);
            }
        }
    }

    return dist[end]; // end에 도달한 거리를 반환 (없으면 -1)
}

int main()
{
    FASTIO;

    int a, b, n, m;

    // 입력 받기
    std::cin >> a >> b >> n >> m;

    std::vector<std::vector<int>> adj(n + 1); // 인접 리스트

    // 변환 가능한 문자 쌍 입력 받기
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // a에서 b까지의 최소 거리를 BFS로 탐색
    int result = bfs(a, b, adj);

    // 결과 출력
    std::cout << result << '\n';

    // int nn;
    // std::cin >> nn;

    return 0;
}
