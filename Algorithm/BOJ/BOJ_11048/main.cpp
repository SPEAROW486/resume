
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 11048
// 0,0부터 n-1, m-1까지
// 아래, 우측, 아래우측대각선 이동이니까 중복 방문 여부를 검사하지 않아도 반드시 탐색은 끝나게되있지만 큐에 계속 푸쉬하게 되니까 메모리 초과뜸.
// 그래서 가지치기 해야함

// DP로 푸는게 최적인거같지만 BFS로 풀었음.

constexpr int MAX = 1001;
int n, m;
int adj[MAX][MAX];
int candy[MAX][MAX];
bool visit[1001][1001];

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> adj[i][j];
        }
    }

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    candy[0][0] = adj[0][0]; // 초기 위치에 있는 사탕 개수

    while (!q.empty())
    {
        std::pair<int, int> front = q.front();
        int cx = front.first;
        int cy = front.second;

        q.pop();

        for (int d = 0; d < 3; ++d)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            // 여태까지 온 지점에서의 사탕이 전부 0이고 방문 지점의 사탕도 0이면 아래 조건으로는 경로 탐색을 안해서 방문 여부에 따라서 무조건 탐색 경로에 넣어줘야할듯.
            if (!visit[nx][ny])
            {
                q.push({nx, ny});
                visit[nx][ny] = true;
                candy[nx][ny] = adj[nx][ny] + candy[cx][cy];
            }
            else if (candy[nx][ny] < candy[cx][cy] + adj[nx][ny])
            {
                // 이미 더 많은 사탕을 가진 경로로 방문한 경우에는 큐에 넣지 않음
                q.push({nx, ny});
                candy[nx][ny] = candy[cx][cy] + adj[nx][ny];
            }
        }
    }

    std::cout << candy[n - 1][m - 1] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}