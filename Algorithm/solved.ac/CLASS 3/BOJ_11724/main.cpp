
#include <bits/stdc++.h>

constexpr int MAX = 510000; // 510000;
int n, m;

std::vector<std::vector<int>> v(MAX);
bool visit[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        v[st].push_back(en);
        v[en].push_back(st);
    }

    int count = 0;
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (visit[i])
        {
            continue;
        }

        q.push(i);
        visit[i] = true;

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

        ++count;
    }

    std::cout << count;

    // int nn;
    // std::cin >> nn;
    return 0;
}