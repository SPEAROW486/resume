
#include <bits/stdc++.h>

constexpr int MAX = 101;

int n;
std::vector<std::vector<int>> v(MAX);
int visit[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int l;
            std::cin >> l;

            if (l != 0)
            {
                v[i].push_back(j);
            }
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        q.push(i);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            const std::vector<int> &links = v[front];
            for (const int &l : links)
            {
                if (visit[l] != 0)
                {
                    continue;
                }

                q.push(l);
                visit[l] = 1;
            }
        }

        for (int j = 0; j < n; ++j)
        {
            std::cout << visit[j] << " ";
        }
        std::cout << "\n";
        std::fill(visit, visit + n, 0);
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}