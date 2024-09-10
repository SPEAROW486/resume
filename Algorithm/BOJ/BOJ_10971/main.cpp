
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
int adj[11][11];      // 인접 행렬
bool visited[11];     // 방문한 도시 체크
int result = INT_MAX; // 최소 비용 저장

// 백트래킹 함수
void tsp(int start, int curr, int cnt, int cost)
{
    // 모든 도시를 다 방문했고 돌아가는 길이 있을때
    if (cnt == n && adj[curr][start] != 0)
    {
        result = std::min(result, cost + adj[curr][start]);
        return;
    }

    // 가지치기: 현재 비용이 이미 최소 비용보다 크다면 중단
    if (cost >= result)
    {
        return;
    }

    // 현재 도시에서 다른 도시로 이동
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && adj[curr][i] != 0)
        {
            visited[i] = true;
            tsp(start, i, cnt + 1, cost + adj[curr][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    FASTIO;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> adj[i][j]; // 인접 행렬 입력
        }
    }

    // 모든 도시에서 출발하는 경우를 탐색
    for (int i = 0; i < n; ++i)
    {
        memset(visited, false, sizeof(visited)); // 방문 배열 초기화
        visited[i] = true;                       // 출발 도시 방문 처리
        tsp(i, i, 1, 0);                         // 도시 i에서 시작
    }

    std::cout << result << '\n'; // 최소 비용 출력

    // int nn;
    // std::cin >> nn;
    return 0;
}