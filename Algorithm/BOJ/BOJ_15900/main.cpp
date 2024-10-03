#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 15900

int n;
std::vector<std::vector<int>> tree;
std::vector<bool> visited;
int total_depth = 0;

// DFS를 이용하여 각 리프 노드까지의 깊이를 구함
void dfs(int node, int depth)
{
    visited[node] = true;
    bool isLeaf = true;

    for (int next : tree[node])
    {
        if (!visited[next])
        {
            isLeaf = false;
            dfs(next, depth + 1);
        }
    }

    // 리프 노드인 경우
    if (isLeaf)
    {
        total_depth += depth;
    }
}

int main()
{
    FASTIO;

    std::cin >> n;
    tree.resize(n + 1);
    visited.resize(n + 1, false);

    // 트리 입력
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 1번 노드를 루트로 DFS 탐색
    dfs(1, 0);

    // 총 리프 노드 깊이의 합이 홀수면 승리
    if (total_depth % 2 == 1)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}
