#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 6118

int main() {
    FASTIO;
    
    int n, m;
    std::cin >> n >> m;  // n : 노드의 개수, m : 간선의 개수

    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> distance(n + 1, -1);

    // 그래프 입력
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // BFS로 최단 거리 계산
    std::queue<int> q;
    q.push(1);
    distance[1] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // 최댓값을 찾아서 해당 거리의 가장 작은 번호를 찾기
    int max_distance = *std::max_element(distance.begin(), distance.end());
    int min_index = -1, count = 0;

    for (int i = 1; i <= n; i++) {
        if (distance[i] == max_distance) {
            if (min_index == -1) {
                min_index = i;
            }
            count++;
        }
    }

    std::cout << min_index << " " << max_distance << " " << count << "\n";

    return 0;
}
