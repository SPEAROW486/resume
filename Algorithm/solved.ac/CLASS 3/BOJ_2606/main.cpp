
#include <bits/stdc++.h>

constexpr int MAX = 101;
int n, m;

bool visit[MAX];
std::vector<std::vector<int>> v(MAX);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int st, en;

        std::cin >> st >> en;

        // 양방향
        v[st].push_back(en);
        v[en].push_back(st);
    }

    std::queue<int> q;
    q.push(1);
    visit[1] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        const std::vector<int> &links = v[front];
        for (const int &l : links)
        {
            if (visit[l])
            {
                continue;
            }

            q.push(l);
            visit[l] = true;
        }
    }

    std::cout << std::count(visit, visit + n + 1, true) - 1;

    // int nn;
    // std::cin >> nn;
    return 0;
}