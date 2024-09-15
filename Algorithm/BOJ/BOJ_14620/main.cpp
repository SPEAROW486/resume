#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14620

// 5x5 격자
int grid[10][10];
// 꽃을 심을 수 있는지 확인하는 배열
bool visited[10][10];

// 상하좌우 방향 정의
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 꽃 하나를 심었을 때의 비용을 계산하는 함수
int calculate_cost(int x, int y)
{
    int cost = grid[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        cost += grid[nx][ny];
    }
    return cost;
}

// 꽃을 심을 수 있는지 확인하는 함수
bool can_place_flower(int x, int y)
{
    if (visited[x][y])
        return false;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny])
            return false;
    }
    return true;
}

// 꽃을 심는 함수
void place_flower(int x, int y, bool state)
{
    visited[x][y] = state;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = state;
    }
}

int main()
{
    FASTIO;

    int n;
    std::cin >> n;
    // 격자 입력 받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> grid[i][j];
        }
    }

    int min_cost = INT_MAX;

    // 3개의 꽃을 심을 위치를 완전탐색
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (!can_place_flower(i, j))
                continue;
            // 첫 번째 꽃을 심는다
            place_flower(i, j, true);
            int first_cost = calculate_cost(i, j);

            for (int k = 1; k < n - 1; k++)
            {
                for (int l = 1; l < n - 1; l++)
                {
                    if (!can_place_flower(k, l))
                        continue;
                    // 두 번째 꽃을 심는다
                    place_flower(k, l, true);
                    int second_cost = calculate_cost(k, l);

                    for (int p = 1; p < n - 1; p++)
                    {
                        for (int q = 1; q < n - 1; q++)
                        {
                            if (!can_place_flower(p, q))
                                continue;
                            // 세 번째 꽃을 심는다
                            place_flower(p, q, true);
                            int third_cost = calculate_cost(p, q);

                            // 현재 심은 세 개의 꽃의 비용 합산
                            int total_cost = first_cost + second_cost + third_cost;
                            min_cost = std::min(min_cost, total_cost);

                            // 세 번째 꽃을 제거
                            place_flower(p, q, false);
                        }
                    }
                    // 두 번째 꽃을 제거
                    place_flower(k, l, false);
                }
            }
            // 첫 번째 꽃을 제거
            place_flower(i, j, false);
        }
    }

    // 최소 비용 출력
    std::cout << min_cost << '\n';

    // int nn;
    // std::cin >> nn;

    return 0;
}
