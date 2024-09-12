
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14248
// 1차원 BFS

int n, s;
std::vector<int> v;

int dx[2] = {-1, 1}; // 왼쪽 오른쪽 방향만이고 거리는 v[i]에 있는 값만큼 이동

std::vector<bool> visit;

int main()
{
    FASTIO;
    std::cin >> n;
    v.resize(n);
    visit.resize(n);
    for (int i = 0; i < n; ++i)
    {
        // 입력의 개수가 많아서 직접 대입
        std::cin >> v[i];
        visit[i] = false;
    }

    std::cin >> s; // 1-based임

    std::queue<int> q;
    q.push(s - 1);
    visit[s - 1] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int d = 0; d < 2; ++d)
        {
            // 현재위치 + 현재 위치에 쓰여있는 값으로 좌우로 이동
            int nx = front + dx[d] * v[front];

            if (nx < 0 || nx >= n)
            {
                continue;
            }

            if (visit[nx])
            {
                continue;
            }

            q.push(nx);
            visit[nx] = true;
        }
    }

    std::cout << std::count(visit.begin(), visit.end(), true) << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}