
#include <bits/stdc++.h>

constexpr int MAX = 101;
int n, m;

std::vector<std::vector<int>> v(MAX);
int visit[MAX];

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

    int ans = 0;
    int min = INT_MAX;
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        int kevin = 0;
        std::fill(visit, visit + MAX, -1);

        q.push(i);
        visit[i] = 0;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            const std::vector<int> &links = v[front];

            for (const int &l : links)
            {
                if (visit[l] != -1)
                {
                    continue;
                }

                q.push(l);
                visit[l] = visit[front] + 1;
                kevin += visit[l];
            }
        }

        if (kevin < min)
        {
            min = kevin;
            ans = i;
        }
    }
    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}