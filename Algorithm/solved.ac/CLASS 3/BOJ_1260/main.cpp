
#include <bits/stdc++.h>

int n, m, v;

constexpr int N_MAX = 1001; // 1001;
constexpr int MAX = 10001;  // 10001;
std::vector<std::vector<int>> vec(MAX);

bool visit[N_MAX];

void dfs(int vv)
{
    visit[vv] = true;
    std::cout << vv << " ";

    std::vector<int> &links = vec[vv];
    std::sort(links.begin(), links.end());
    for (const int &l : links)
    {
        if (visit[l])
        {
            continue;
        }
        dfs(l);
    }
}

void bfs()
{
    std::queue<int> q;
    q.push(v);
    visit[v] = true;
    std::cout << v << " ";

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        std::vector<int> &links = vec[front];
        std::sort(links.begin(), links.end());
        for (const int &l : links)
        {
            if (visit[l])
            {
                continue;
            }

            q.push(l);
            visit[l] = true;
            std::cout << l << " ";
        }
    }
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n >> m >> v;

    for (int i = 0; i < m; ++i)
    {
        int start, end;
        std::cin >> start >> end;

        vec[start].push_back(end);
        vec[end].push_back(start);
    }

    dfs(v);
    std::cout << "\n";
    std::fill(visit, visit + N_MAX, false);
    bfs();

    // int nn;
    // std::cin >> nn;
    return 0;
}