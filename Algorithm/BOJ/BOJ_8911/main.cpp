
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// 왼쪽 위 오른쪽 아래
int px, py;
int pxmin = 0, pymin = 0;
int pxmax = 0, pymax = 0;

int dir = 1;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void turn(char c)
{
    if (c == 'L')
    {
        --dir;
        if (dir < 0)
        {
            dir = 3;
        }
    }
    else
    {
        ++dir;
        if (dir > 3)
        {
            dir = 0;
        }
    }
}

void move(char c)
{

    if (c == 'F')
    {
        px += dx[dir];
        py += dy[dir];
    }
    else
    {
        px -= dx[dir];
        py -= dy[dir];
    }

    pxmin = std::min(pxmin, px);
    pymin = std::min(pymin, py);
    pxmax = std::max(pxmax, px);
    pymax = std::max(pymax, py);
}

int main()
{
    FASTIO;
    int tc;
    std::cin >> tc;
    while (tc--)
    {
        std::string s;
        std::cin >> s;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'L' || s[i] == 'R')
            {
                turn(s[i]);
            }
            else
            {
                move(s[i]);
            }
        }

        int x = pxmax - pxmin;
        int y = pymax - pymin;

        std::cout << x * y << "\n";

        px = 0;
        py = 0;
        pxmin = 0;
        pymin = 0;
        pxmax = 0;
        pymax = 0;
        dir = 1;
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}