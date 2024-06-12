
#include <bits/stdc++.h>

int n, m;

int main()
{
    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n >> m;

        std::queue<std::pair<int, int>> q;
        std::priority_queue<int> pq;
        for (int i = 0; i < n; ++i)
        {
            int p;
            std::cin >> p;
            q.push({i, p});
            pq.push(p);
        }

        int order = 1;
        while (!q.empty())
        {
            int idx, p;
            std::tie(idx, p) = q.front();
            q.pop();
            if (p == pq.top())
            {
                if (idx == m)
                {
                    std::cout << order << "\n";
                }
                ++order;
                pq.pop();
            }
            else
            {
                q.push({idx, p});
            }
        }
    }

    return 0;
}