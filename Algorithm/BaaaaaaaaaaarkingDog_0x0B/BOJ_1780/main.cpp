
#include <bits/stdc++.h>

constexpr int MAX = 2188; // 3^7 +1;
int paper[MAX][MAX];
int cnt[3];

// 1. 함수의 정의
// n이랑 찾으려고하는 숫자를 넣으면 될듯
// 값을 읽어봐야할거같으니까 좌상단 좌표를 넣어줘야할거같은데

bool IsEqual(int n, int r, int c)
{
    for (int i = r; i < r + n; ++i)
    {
        for (int j = c; j < c + n; ++j)
        {
            if (paper[i][j] != paper[r][c])
            {
                return false;
            }
        }
    }
    return true;
}

void Solve(int n, int r, int c)
{
    // n은 3^K 제곱형태로
    // 그럼 제곱근을 구하면

    // 2. 베이스 컨디션
    if (IsEqual(n, r, c))
    {
        ++cnt[paper[r][c] + 1];
        return;
    }

    // 3. 재귀식
    int divider = n / 3;
    // 등분한 종이에서 값이 -1,0,1 3종류라 실제로 값을 읽어야할거같은데..

    // 9방향의 값을 다 더해야 할거같은데
    // Solve(divider, r, c);
    // Solve(divider, r, c + divider);
    // Solve(divider, r, c + divider * 2);

    // Solve(divider, r + divider, c);
    // Solve(divider, r + divider, c + divider);
    // Solve(divider, r + divider, c + divider * 2);

    // Solve(divider, r + divider * 2, c);
    // Solve(divider, r + divider * 2, c + divider);
    // Solve(divider, r + divider * 2, c + divider * 2);

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            Solve(divider, r + divider * i, c + divider * j);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> paper[i][j];
        }
    }

    Solve(n, 0, 0);
    for (int i : cnt)
    {
        std::cout << i << "\n";
    }

    return 0;
}