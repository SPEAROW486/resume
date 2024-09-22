
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1325
// BFS 응용

int n, m;

std::vector<std::vector<int>> edges;
std::vector<std::pair<int, int>> cnt;
int max = 0;

void bfs(int start)
{
    std::queue<int> q;
    q.push(start);

    std::vector<bool> visit(n + 1, false);
    visit[start] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        const std::vector<int> &ed = edges[front];
        for (const int &l : ed)
        {
            if (visit[l])
            {
                continue;
            }

            q.push(l);
            visit[l] = true;
            ++cnt[l].second;

            max = std::max(max, cnt[l].second);
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    edges.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = {i, 0};
    }

    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;
        edges[st].push_back(en);
    }

    for (int i = 1; i <= n; ++i)
    {
        bfs(i);
    }

    auto compare = [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
    {
        if (lhs.second != rhs.second)
        {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    };
    std::sort(cnt.begin(), cnt.end(), compare);

    for (int i = 0; i < cnt.size(); ++i)
    {
        if (cnt[i].second == max)
        {
            std::cout << cnt[i].first << " ";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}