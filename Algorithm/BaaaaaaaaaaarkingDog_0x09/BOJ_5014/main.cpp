
#include <bits/stdc++.h>

constexpr int MAX = 1000001;
int dist[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int f, s, g, u, d;
    std::cin >> f >> s >> g >> u >> d;

    // 처음부터 이미 같은 층이라면 누를 필요가 없으므로 0번 눌렀다고 해야함.
    if (s == g)
    {
        std::cout << 0;
        return 0;
    }

    std::fill(dist, dist + MAX, -1);

    std::queue<int> q;
    q.push(s);
    dist[s] = 0;

    int dx[2] = {u, -d};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 2; ++dir)
        {
            int nx = cur + dx[dir];
            // 돌아가는데 문제가 없어보여도 최저층이 1층이기때문에 0층에 방문하면안되는게 문제 요구사항임.
            // 이거 안했어가지고 틀렸음.
            if (nx <= 0 || nx > f)
            {
                continue;
            }

            if (dist[nx] != -1)
            {
                continue;
            }

            q.push(nx);
            dist[nx] = dist[cur] + 1;
            if (nx == g)
            {
                std::cout << dist[nx];
                return 0;
            }
        }
    }

    std::cout << "use the stairs";
    return 0;
}