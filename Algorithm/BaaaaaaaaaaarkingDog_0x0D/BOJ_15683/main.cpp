
#include <bits/stdc++.h>

constexpr int MAX = 8;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int buf[MAX][MAX];
std::vector<std::pair<int, int>> cctv;

int area_size = std::numeric_limits<int>::max();

bool OOB(int a, int b)
{
    return a < 0 || a >= n || b < 0 || b >= m;
}

void fill_area(int x, int y, int dir)
{
    dir = dir % 4;
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        if (OOB(nx, ny))
        {
            return;
        }

        if (buf[nx][ny] == 6)
        {
            return;
        }

        if (buf[nx][ny] != 0)
        {
            continue;
        }

        buf[nx][ny] = -1;
    }
}

void func(int k)
{
    if (k == cctv.size())
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (buf[i][j] == 0)
                {
                    ++cnt;
                }
            }
        }
        area_size = std::min(cnt, area_size);
        return;
    }

    int x, y;
    std::tie(x, y) = cctv[k];

    int buf2[MAX][MAX];
    for (int dir = 0; dir < 4; ++dir)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                buf2[i][j] = buf[i][j];
            }
        }

        // back tracking body
        if (buf[x][y] == 1)
        {
            fill_area(x, y, dir);
        }
        else if (buf[x][y] == 2)
        {
            fill_area(x, y, dir);
            fill_area(x, y, dir + 2);
        }
        else if (buf[x][y] == 3)
        {
            fill_area(x, y, dir);
            fill_area(x, y, dir + 1);
        }
        else if (buf[x][y] == 4)
        {
            fill_area(x, y, dir);
            fill_area(x, y, dir + 1);
            fill_area(x, y, dir + 2);
        }
        else if (buf[x][y] == 5)
        {
            fill_area(x, y, dir);
            fill_area(x, y, dir + 1);
            fill_area(x, y, dir + 2);
            fill_area(x, y, dir + 3);
        }

        func(k + 1);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                buf[i][j] = buf2[i][j];
            }
        }
    }
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> buf[i][j];
            if (buf[i][j] != 0 && buf[i][j] != 6)
            {
                cctv.push_back({i, j});
            }
        }
    }

    func(0);
    std::cout << area_size;
    return 0;
}