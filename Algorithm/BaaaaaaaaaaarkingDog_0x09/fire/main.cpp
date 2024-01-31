#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

struct Point
{
public:
    Point() = default;
    Point(int r, int c) : row(r), col(c)
    {
    }

    Point operator+(const Point &rhs) const
    {
        return Point(row + rhs.row, col + rhs.col);
    }

    int row = 0;
    int col = 0;
};

// 상하좌우
static Point SearchDirection[4] = {
    Point(-1, 0),
    Point(1, 0),
    Point(0, -1),
    Point(0, 1)};

bool IsContain(const Point &p, const int row, const int col)
{
    return (p.row >= 0 && p.row < row) && (p.col >= 0 && p.col < col);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int r, c;
    std::cin >> r >> c;

    const int BUF_SIZE = 1000;
    char maze[BUF_SIZE][BUF_SIZE];
    bool buf_j[BUF_SIZE][BUF_SIZE];
    int buf_f[BUF_SIZE][BUF_SIZE];

    std::fill(&buf_j[0][0], &buf_j[0][0] + sizeof(buf_j) / sizeof(bool), 0);
    std::fill(&buf_f[0][0], &buf_f[0][0] + sizeof(buf_f) / sizeof(int), INT_MAX);

    std::queue<Point> queue_f;
    std::queue<std::pair<Point, int>> queue_j;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cin >> maze[i][j];

            if (maze[i][j] == 'J')
            {
                queue_j.push(std::pair<Point, int>(Point(i, j), 0));
            }

            if (maze[i][j] == 'F')
            {
                queue_f.push(Point(i, j));
                buf_f[i][j] = 0;
            }
        }
    }

    while (!queue_f.empty())
    {
        Point p = queue_f.front();
        for (const Point &direction : SearchDirection)
        {
            Point u = p + direction;
            if (IsContain(u, r, c))
            {
                // 지나갈수 있는 공간
                if (maze[u.row][u.col] == '.' && buf_f[u.row][u.col] == INT_MAX)
                {
                    queue_f.push(u);
                    buf_f[u.row][u.col] = buf_f[p.row][p.col] + 1;
                }
            }
        }
        queue_f.pop();
    }

    while (!queue_j.empty())
    {
        Point p = queue_j.front().first;
        int minimum_time = queue_j.front().second;

        if (p.row == 0 || p.row == r - 1 || p.col == 0 || p.col == c - 1)
        {
            std::cout << minimum_time + 1;
            return 0;
        }

        for (const Point &direction : SearchDirection)
        {
            Point u = p + direction;
            if (IsContain(u, r, c))
            {
                if (maze[u.row][u.col] == '.' && buf_f[u.row][u.col] > minimum_time + 1 && buf_j[u.row][u.col] == false)
                {
                    queue_j.push(std::pair<Point, int>(u, minimum_time + 1));
                    buf_j[u.row][u.col] = true;
                }
            }
        }

        queue_j.pop();
    }

    std::cout << "IMPOSSIBLE";

    return 0;
}