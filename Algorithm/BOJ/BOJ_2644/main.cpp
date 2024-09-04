
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2644
// 그래프 ?

constexpr int MAX = 101;
int visit[MAX];

int main()
{
    FASTIO;

    int n, m;
    std::cin >> n;

    int st, en;
    std::cin >> st >> en;

    std::cin >> m;

    std::vector<std::vector<int>> edge(MAX);
    for (int i = 0; i < m; ++i)
    {
        int s, e;
        std::cin >> s >> e;

        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    std::fill(visit, visit + MAX, -1);

    std::queue<int> q;
    q.push(st);
    visit[st] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (const int e : edge[front])
        {
            if (visit[e] != -1)
            {
                continue;
            }

            q.push(e);
            visit[e] = visit[front] + 1;
        }
    }

    std::cout << visit[en] << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}