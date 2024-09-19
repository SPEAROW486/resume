
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 24479

int n, m, r;

std::vector<std::vector<int>> edges;
std::vector<bool> visit;
std::vector<int> depth;

void dfs(int start, int dep)
{
    visit[start] = true;
    depth[start] = dep;

    std::vector<int> &e = edges[start];

    for (const int &l : e)
    {
        if (visit[l])
        {
            continue;
        }

        dfs(l, dep + 1);
    }
}

int main()
{
    FASTIO;

    std::cin >> n >> m >> r;
    edges.resize(n + 1);
    visit.resize(n + 1, false);
    depth.resize(n + 1, -1);

    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        edges[st].push_back(en);
        edges[en].push_back(st);
    }

    for (int i = 0; i < edges.size(); ++i)
    {
        std::vector<int> &e = edges[i];
        std::sort(e.begin(), e.end());
    }

    dfs(r, 0);

    for (int i = 1; i <= n; ++i)
    {
        std::cout << depth[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}