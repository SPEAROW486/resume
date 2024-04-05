
#include <bits/stdc++.h>

constexpr int MAX = 2188; // 3^7 +1;
int paper[MAX][MAX];

// 1. 함수의 정의
// n이랑 찾으려고하는 숫자를 넣으면 될듯
// 값을 읽어봐야할거같으니까 좌상단 좌표를 넣어줘야할거같은데
int Solve(int n, int r, int c, int number)
{
    // n은 3^K 제곱형태로
    // 그럼 제곱근을 구하면

    // 2. 베이스 컨디션
    if (n == 1)
    {
        // 찾으려는 값이면 1
        // std::cout << r << "," << c << "=" << paper[r][c] << ", find number = " << number << "\n";
        return paper[r][c] == number ? 1 : 0;
    }

    // 3. 재귀식
    int divider = n / 3;
    // 등분한 종이에서 값이 -1,0,1 3종류라 실제로 값을 읽어야할거같은데..

    int count = 0;
    // 9방향의 값을 다 더해야 할거같은데
    count += Solve(divider, r, c, number);
    count += Solve(divider, r, c + divider, number);
    count += Solve(divider, r, c + divider * 2, number);

    count += Solve(divider, r + divider, c, number);
    count += Solve(divider, r + divider, c + divider, number);
    count += Solve(divider, r + divider, c + divider * 2, number);

    count += Solve(divider, r + divider * 2, c, number);
    count += Solve(divider, r + divider * 2, c + divider, number);
    count += Solve(divider, r + divider * 2, c + divider * 2, number);

    // n * n 사이즈의 종이가 전부 같은 숫자면 몫은 1일거고, 아니면 0
    // 전부 같은 숫자가 아니면 나머지가 개수일듯?
    count = (count / 9) + (count % 9);
    std::cout << count << "," << n << "\n";
    return count + (count / 9) + (count % 9);
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> paper[i][j];
        }
    }

    std::cout << "\n\n";

    std::cout << Solve(n, 0, 0, -1) << "\n";
    // std::cout << Solve(n, 0, 0, 0) << "\n";
    // std::cout << Solve(n, 0, 0, 1) << "\n";

    int nn;
    std::cin >> nn;

    return 0;
}