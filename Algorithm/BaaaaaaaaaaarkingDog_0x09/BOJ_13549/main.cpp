
#include <bits/stdc++.h>

constexpr int MAX = 200002; // 200002;
int dist[MAX];

// 시작위치를 0
// 기본값은 -1로 초기화

// 1차원 배열 BFS
// 0초 시점에 순간이동이있음.
// 1초후에 X-1, X+1이고
// 즉 2방향 탐색을 시작하는 순간(X-1, X+1)을 하기전에 기존위치에서 순간이동된 위치를 먼저 탐색하면 되지 않을까?

int n, k;
bool IsOutOfRanage(int nx)
{
    return nx < 0 || nx >= MAX;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> k;

    std::fill(&dist[0], &dist[MAX], -1);
    std::queue<int> q;

    // entry point
    dist[n] = 0;
    q.push(n);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        // teleport
        if (!IsOutOfRanage(2 * cur) && dist[2 * cur] == -1)
        {
            // 수빈이가 99999위치에이쓰면 순간이동하면 범위를 넘어버리는데?
            // 입력이 10만 언더지, 순간이동한 위치까지 10만 언더라는 보장이 없네
            // 그럼 버퍼의 사이즈는 2배다
            // 만약 순간이동은 할 수 있으면 그 위치도 거리를 기록해주고 큐에 넣어줌.
            dist[2 * cur] = dist[cur];
            q.push(2 * cur);
        }

        // 2 Way
        for (int nx : {cur - 1, cur + 1})
        {
            if (IsOutOfRanage(nx))
            {
                continue;
            }

            if (dist[nx] != -1)
            {
                continue;
            }

            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    // 찾을수 없는 케이스가 존재하나??
    // 찾을 수 없을 떄의 출력을 어떻게 하라는 말이 없었으니 무조건 찾나본데
    std::cout << dist[k];

    return 0;
}