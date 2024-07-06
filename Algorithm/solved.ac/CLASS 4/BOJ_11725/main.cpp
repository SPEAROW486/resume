
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

constexpr int MAX = 100001; // 100001
std::vector<std::vector<int>> edges(MAX);
int parent[MAX];
bool visit[MAX];

void find_parent(int st)
{
    const std::vector<int> &e = edges[st];
    for (const int &elem : e)
    {
        if (visit[elem])
        {
            continue;
        }
        parent[elem] = st;
        visit[elem] = true;
        find_parent(elem);
    }
}

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        edges[st].push_back(en);
        edges[en].push_back(st);
    }

    find_parent(1);
    for (int i = 2; i <= n; ++i)
    {
        std::cout << parent[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}