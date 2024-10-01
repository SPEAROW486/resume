#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 3184

int R, C;
std::vector<std::string> farm;
std::vector<std::vector<bool>> visited;

int dx[4] = {0, 0, 1, -1}; // 상하좌우 방향 벡터
int dy[4] = {1, -1, 0, 0};

// 영역을 탐색하면서 양과 늑대의 수를 반환하는 함수
std::pair<int, int> bfs(int x, int y)
{
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int sheep = 0, wolf = 0;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 현재 위치가 양일 경우
        if (farm[cx][cy] == 'o')
        {
            sheep++;
        }
        // 현재 위치가 늑대일 경우
        else if (farm[cx][cy] == 'v')
        {
            wolf++;
        }

        // 상하좌우로 이동
        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && farm[nx][ny] != '#')
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return {sheep, wolf};
}

int main()
{
    FASTIO;

    std::cin >> R >> C;

    farm.resize(R);
    visited.resize(R, std::vector<bool>(C, false));

    for (int i = 0; i < R; ++i)
    {
        std::cin >> farm[i];
    }

    int totalSheep = 0, totalWolf = 0;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (!visited[i][j] && farm[i][j] != '#')
            {
                std::pair<int, int> result = bfs(i, j); // 결과를 std::pair로 저장
                int sheep = result.first;
                int wolf = result.second;

                // 양이 늑대보다 많으면 늑대는 죽고 양이 살아남음
                if (sheep > wolf)
                {
                    totalSheep += sheep;
                }
                else
                {
                    totalWolf += wolf;
                }
            }
        }
    }

    std::cout << totalSheep << " " << totalWolf << "\n";

    return 0;
}
