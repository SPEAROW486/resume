#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 12761

int main()
{
    FASTIO;

    // 입력 변수 선언
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    // 방문 여부와 이동 횟수를 저장하는 배열
    std::vector<int> dist(100001, -1);
    std::queue<int> q;

    // 초기 위치 설정
    q.push(n);
    dist[n] = 0;

    // BFS를 이용하여 최소 이동 횟수 탐색
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 현재 위치에서 이동할 수 있는 8가지 방법
        std::vector<int> moves = {cur + 1, cur - 1, cur + a, cur - a, cur + b, cur - b, cur * a, cur * b};
        for (int next : moves)
        {
            // 범위 체크 및 방문하지 않은 위치 확인
            if (next >= 0 && next <= 100000 && dist[next] == -1)
            {
                dist[next] = dist[cur] + 1; // 이동 횟수 갱신
                q.push(next);

                // 목표 위치 도달 시 출력 및 종료
                if (next == m)
                {
                    std::cout << dist[m] << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}
