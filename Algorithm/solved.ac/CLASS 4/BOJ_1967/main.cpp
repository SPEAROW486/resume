
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 10001;
constexpr int ROOT = 1;

std::vector<std::vector<std::pair<int, int>>> edges;
int n;
int ans = 0;
int longest_node = 0;
bool visit[MAX];

void dfs(int start, int sum)
{
    if (sum > ans)
    {
        ans = sum;
        longest_node = start;
    }

    const std::vector<std::pair<int, int>> &e = edges[start];
    for (const std::pair<int, int> &p : e)
    {
        const int pNode = p.first;
        const int pWeight = p.second;

        if (visit[pNode])
        {
            continue;
        }

        visit[pNode] = true;
        dfs(pNode, sum + pWeight);
        visit[pNode] = false;
    }
}

int main()
{
    FASTIO;
    std::cin >> n;

    edges.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int st, en, wei;
        std::cin >> st >> en >> wei;

        edges[st].push_back({en, wei});
        edges[en].push_back({st, wei});
    }

    // 루트에서 가장 먼걸 찾고
    // 찾은 노드에서 가장 먼 노드를 찾으면 거기까지의 거리가 지름 ㅇㅇ

    visit[ROOT] = true;
    dfs(ROOT, 0);
    visit[ROOT] = false;

    visit[longest_node] = true;
    dfs(longest_node, 0);
    visit[longest_node] = false;

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}