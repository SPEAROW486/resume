
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001;
int c, r, k;

int board[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    FASTIO;
    std::cin >> c >> r;
    std::cin >> k;

    int num = 1;
    int goal = c * r;

    int cx = 0;
    int cy = 0;
    int dir = 0;

    int ar = -1;
    int ac = -1;
    while (num <= goal)
    {
        board[cx][cy] = num;
        if (board[cx][cy] == k)
        {
            ar = cx;
            ac = cy;
            break;
        }

        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] != 0)
        {
            dir = (dir + 1) % 4;
            nx = cx + dx[dir];
            ny = cy + dy[dir];
        }

        cx = nx;
        cy = ny;

        ++num;
    }

    if (ar != -1 && ac != -1)
    {
        std::cout << ac + 1 << " " << ar + 1 << "\n";
    }
    else
    {
        std::cout << "0\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}