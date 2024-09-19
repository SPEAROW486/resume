
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 24480

int n, m, r;
int order = 1; // 방문 순서

std::vector<std::vector<int>> edges;
std::vector<int> visit;

void dfs(int start)
{
    visit[start] = order++;

    std::vector<int> &e = edges[start];

    for (const int &l : e)
    {
        if (visit[l])
        {
            continue;
        }

        dfs(l);
    }
}

int main()
{
    FASTIO;

    std::cin >> n >> m >> r;
    edges.resize(n + 1);
    visit.resize(n + 1, 0);

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
        std::sort(e.begin(), e.end(), std::greater<>());
    }

    dfs(r);

    for (int i = 1; i <= n; ++i)
    {
        std::cout << visit[i] << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}