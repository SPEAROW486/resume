
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    int n, target;
    std::cin >> n >> target;

    // 2D 배열 초기화
    std::vector<std::vector<int>> snail(n, std::vector<int>(n, 0));

    // 방향: 위, 오른쪽, 아래, 왼쪽 순서로 진행 (시계 반대 방향 달팽이 배열)
    int dirX[] = {-1, 0, 1, 0};
    int dirY[] = {0, 1, 0, -1};

    // 시작점 중앙
    int x = n / 2;
    int y = n / 2;

    int num = 1;                  // 배열에 채울 숫자 시작
    int targetX = x, targetY = y; // 목표 숫자의 위치 저장

    snail[x][y] = num; // 중앙 시작점 채우기

    // 달팽이 배열 만들기
    int step = 1; // 이동하는 단계 수

    while (num < n * n)
    {
        for (int i = 0; i < 4; i++)
        { // 위, 오른쪽, 아래, 왼쪽 네 방향으로 이동
            for (int j = 0; j < step; j++)
            { // 해당 방향으로 step만큼 이동
                x += dirX[i];
                y += dirY[i];
                num++;

                if (num > n * n)
                    break; // 숫자가 다 채워지면 종료

                snail[x][y] = num;

                if (num == target)
                { // 목표 숫자를 찾은 경우 위치 저장
                    targetX = x;
                    targetY = y;
                }
            }

            if (i % 2 == 1)
            {
                step++; // 오른쪽과 왼쪽 방향 이동 후에 step 증가
            }
        }
    }

    // 배열 출력
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << snail[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 목표 숫자의 위치 출력 (1-based index)
    std::cout << targetX + 1 << " " << targetY + 1 << std::endl;

    // int nn;
    // std::cin >> nn;
    return 0;
}
