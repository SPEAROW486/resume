
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 200001; // 200001;  // 99999에서 순간이동할수도있으니까 넓게 잡음
int n, k;
int dist[MAX];
int cnt[MAX]; // 해당 정점에 몇번 도달했는지

void bfs()
{
    std::queue<int> q;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int nx : {front - 1, front + 1, front * 2})
        {
            if (nx < 0 || nx >= MAX)
            {
                continue;
            }

            if (dist[nx] != 0)
            {
                if (dist[nx] == dist[front] + 1)
                {
                    cnt[nx] += cnt[front];
                }
                continue;
            }

            q.push(nx);
            dist[nx] = dist[front] + 1;
            cnt[nx] = cnt[front];
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> k;

    if (n == k)
    {
        std::cout << 0 << "\n"
                  << 1;
        return 0;
    }

    bfs();

    std::cout << dist[k] << "\n";
    std::cout << cnt[k];

    // int nn;
    // std::cin >> nn;

    return 0;
}