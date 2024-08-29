
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    // 문제 잘 읽어보고 B에 대한 정리를 A에 대한 정리로 수정해서 보면 그렇게 어려운 문제는 아니였음..
    int H, W, X, Y;
    std::cin >> H >> W >> X >> Y;

    std::vector<std::vector<int>> B(H + X, std::vector<int>(W + Y));
    std::vector<std::vector<int>> A(H, std::vector<int>(W));

    // 배열 B 입력 받기
    for (int i = 0; i < H + X; ++i)
    {
        for (int j = 0; j < W + Y; ++j)
        {
            std::cin >> B[i][j];
        }
    }

    // 배열 A 복원하기
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i >= X && j >= Y)
            {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            }
            else
            {
                A[i][j] = B[i][j];
            }
        }
    }

    // 배열 A 출력
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
