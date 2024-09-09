#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 5567

int n, m;
std::vector<std::vector<int>> edges;

int main()
{
    FASTIO;
    std::cin >> n;
    std::cin >> m;

    edges.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        edges[st].push_back(en);
        edges[en].push_back(st);
    }

    // 양방향 그래프로 구성했으니까 1,3 이든 3,1이든 추적가능함.

    std::queue<std::pair<int, int>> q;
    std::vector<bool> visit(n + 1, false);
    q.push({1, 0});
    visit[1] = true;

    int ans = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth > 0 && depth <= 2)
        {
            ++ans;
        }

        const std::vector<int> &edge = edges[cur];
        for (const int &l : edge)
        {
            if (visit[l])
            {
                continue;
            }

            q.push({l, depth + 1});
            visit[l] = true;
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}
