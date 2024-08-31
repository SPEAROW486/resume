#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 25418
// BFS?

constexpr int MAX = 1000001;
int a, k;
int visit[MAX];

int main()
{
    FASTIO;
    std::cin >> a >> k;

    // 방문하지 않은곳은 전부 -1로 초기화
    std::fill(visit, visit + MAX, -1);

    std::queue<int> q;
    q.push(a);

    // 시작지점
    visit[a] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)
        {
            std::cout << visit[cur] << "\n";
            return 0;
        }

        for (int i : {cur + 1, cur * 2})
        {
            if (i < 1 || i >= MAX)
            {
                continue;
            }

            if (visit[i] != -1)
            {
                continue;
            }

            q.push(i);
            visit[i] = visit[cur] + 1;
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
