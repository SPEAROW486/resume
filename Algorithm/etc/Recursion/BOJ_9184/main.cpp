
#include <bits/stdc++.h>

constexpr int MAX = 21;
int buf[MAX][MAX][MAX];

int Solve(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return Solve(20, 20, 20);
    }

    // 입력 값 범위때문에 범위를 벗어나는 경우가 있어서 여기 있어야함.
    if (buf[a][b][c] != 0)
    {
        return buf[a][b][c];
    }

    if (a < b && b < c)
    {
        return buf[a][b][c] = Solve(a, b, c - 1) + Solve(a, b - 1, c - 1) - Solve(a, b - 1, c);
    }

    return buf[a][b][c] = Solve(a - 1, b, c) + Solve(a - 1, b - 1, c) + Solve(a - 1, b, c - 1) - Solve(a - 1, b - 1, c - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (true)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << Solve(a, b, c) << '\n';
    }

    return 0;
}