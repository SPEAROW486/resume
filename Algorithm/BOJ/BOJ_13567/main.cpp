
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int m, n;
int dir = 0; // 좌회전 ++, --우회전
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int y, x;

void move(int n)
{
    y += dy[dir] * n;
    x += dx[dir] * n;
}

void turn(int n)
{
    if (n == 0)
    {
        ++dir;
        if (dir > 3)
        {
            dir = 0;
        }
    }
    else
    {
        --dir;
        if (dir < 0)
        {
            dir = 3;
        }
    }
}

int main()
{
    // FASTIO;

    std::cin >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;

        int n;
        std::cin >> n;

        if (str == "MOVE")
        {
            move(n);
        }
        else
        {
            turn(n);
        }

        if (y < 0 || y > m || x < 0 || x > m)
        {
            std::cout << -1 << "\n";
            return 0;
        }
    }

    std::cout << y << " " << x << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}