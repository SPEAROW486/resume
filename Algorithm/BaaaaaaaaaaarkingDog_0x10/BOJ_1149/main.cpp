
#include <bits/stdc++.h>

// - DP
// 1. 테이블 정의하기
// 2. 점화식 찾기
// 3. 초기값 정하기

// 테이블의 정의 (i번째 집까지 칠해야하는데, 색깔이 총 3종류니까 ) -> 혼자 못풀어서 테이블의 정의만 강의 참고 했고 나머진 혼자 품..
// 조건을 테이블로 표현 할 수 있어야함..
// d[i][0] = i번째 집까지 칠할때의 최솟값 단 i번째 집은 빨간색
// d[i][1] = i번째 집까지 칠할때의 최솟값 단 i번째 집은 초록색
// d[i][2] = i번째 집까지 칠할때의 최솟값 단 i번째 집은 파랑색

// 점화식 i번째 집이 빨간색이면, i-1에는 초록색, 파랑색이 올 수 있으므로 이 2개중 작은 값 + 현재 색상 값
// d[i][0] = std::min(d[i-1][1], d[i-1][2]) + buf[0];

constexpr int MAX = 1001;
int buf[MAX];
int d[MAX][3];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int result = 0;
    int i = 1;
    while (n--)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> buf[j];
        }

        if (i == 1)
        {
            d[i][0] = buf[0];
            d[i][1] = buf[1];
            d[i][2] = buf[2];
        }
        else
        {
            // i >= 2이상일때 i가 빨강색 집이라고 가정하면 i-1에는 초록과 파랑이 올 수 있음.
            d[i][0] = std::min(d[i - 1][1], d[i - 1][2]) + buf[0];
            d[i][1] = std::min(d[i - 1][0], d[i - 1][2]) + buf[1];
            d[i][2] = std::min(d[i - 1][0], d[i - 1][1]) + buf[2];
        }

        ++i;
    }

    int min = std::min(d[i - 1][0], d[i - 1][1]);
    min = std::min(min, d[i - 1][2]);

    std::cout << min;
    // int nn;
    // std::cin >> nn;

    return 0;
}