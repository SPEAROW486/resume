
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 11060
// 1차원 BFS ??

constexpr int MAX = 10001;
int n;
std::vector<int> v;

int visit[MAX];

int main()
{
    FASTIO;

    std::fill(visit, visit + MAX, -1);

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::queue<int> q;
    q.push(0);
    visit[0] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        int jump = v[curr];

        for (int nx = curr; nx <= curr + jump; ++nx)
        {
            if (nx < 0 || nx >= n)
            {
                continue;
            }

            if (visit[nx] != -1)
            {
                continue;
            }

            q.push(nx);
            visit[nx] = visit[curr] + 1;
        }
    }

    std::cout << visit[n - 1] << "\n";

    return 0;
}
