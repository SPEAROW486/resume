
#include <bits/stdc++.h>

constexpr int MAX = 129;

int paper[MAX][MAX];
int cnt[2];
// 2^N * 2^N 종이에서 정사각형 모양의 색종이를 만드는 문제 (하얀색, 파란색)
// 4등분
// 전체적으로 Z 문제랑 유사한 문제인데, 색종이의 개수와 파란색 색종이의 개수를 구하는문제.
// 종이의 개수랑도 유사한데? 그냥 4등분이지..
// 1개가 될 때까지 4등분하는거고
// 등분하기전에 모두 같은 거로 이루어져있는지

bool IsEqual(int x, int y, int n)
{
    for (int i = x; i < x + n; ++i)
    {
        for (int j = y; j < y + n; ++j)
        {
            if (paper[i][j] != paper[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

void Solve(int x, int y, int n)
{
    if (IsEqual(x, y, n))
    {
        ++cnt[paper[x][y]];
        return;
    }

    int half = n / 2;
    // 4등분 한 각각의 색종이에도 다시 이걸 적용해야하니까..

    Solve(x, y, half);
    Solve(x + half, y, half);
    Solve(x, y + half, half);
    Solve(x + half, y + half, half);

    return;
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

    Solve(0, 0, n);

    for (const int &elem : cnt)
    {
        std::cout << elem << "\n";
    }

    return 0;
}