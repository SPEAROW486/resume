#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1303

// 방향 벡터 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;                               // 전장의 크기 (가로 N, 세로 M)
std::vector<std::string> field;         // 전장
std::vector<std::vector<bool>> visited; // 방문 여부 기록

// 너비 우선 탐색 (BFS) 함수
int bfs(int x, int y, char team)
{
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int count = 1;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            // 전장 내에서만 이동
            if (nx >= 0 && nx < M && ny >= 0 && ny < N)
            {
                if (!visited[nx][ny] && field[nx][ny] == team)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    FASTIO;

    std::cin >> N >> M;
    field.resize(M);
    visited.resize(M, std::vector<bool>(N, false));

    // 전장 입력 받기
    for (int i = 0; i < M; i++)
    {
        std::cin >> field[i];
    }

    int whitePower = 0, bluePower = 0;

    // 전장 탐색
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                // 현재 병사의 팀에 따라 병사 수를 세고 전력 계산
                int soldiers = bfs(i, j, field[i][j]);
                if (field[i][j] == 'W')
                {
                    whitePower += soldiers * soldiers;
                }
                else
                {
                    bluePower += soldiers * soldiers;
                }
            }
        }
    }

    // 결과 출력
    std::cout << whitePower << ' ' << bluePower << '\n';

    return 0;
}
