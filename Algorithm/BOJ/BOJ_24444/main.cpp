
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 24444

int n, m, r;

std::vector<int> visit;
std::vector<std::vector<int>> edges;

int main()
{
    FASTIO;

    std::cin >> n >> m >> r;

    visit.resize(n + 1);
    edges.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        edges[st].push_back(en);
        edges[en].push_back(st);
    }

    for (int i = 0; i < edges.size(); ++i)
    {
        std::sort(edges[i].begin(), edges[i].end());
    }

    int order = 1;
    std::queue<int> q;
    q.push(r);
    visit[r] = order++;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        const std::vector<int> &edge = edges[front];
        for (const int &e : edge)
        {
            if (visit[e] != 0)
            {
                continue;
            }

            q.push(e);
            visit[e] = order++;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << visit[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}