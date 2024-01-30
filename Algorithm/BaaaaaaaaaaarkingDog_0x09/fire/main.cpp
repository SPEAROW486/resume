#include <iostream>
#include <queue>

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

    char maze[4][4] = {0};
    int buf_j[4][4] = {0};
    int buf_f[4][4] = {0};

    std::queue<Point> queue_f;
    std::queue<Point> queue_j;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            bool is_fire = false;
            std::cin >> maze[i][j];

            if (maze[i][j] == 'J')
            {
                queue_j.push(Point(i, j));
            }

            if (maze[i][j] == 'F')
            {
                queue_f.push(Point(i, j));
                is_fire = true;
                buf_f[i][j] = 0;
            }

            if (!is_fire)
            {
                buf_f[i][j] = INT_MAX;
            }
        }
    }

    // 1. bfs buf_f
    // 2. bfs buf_j

    while (!queue_j.empty())
    {
        Point point_f = queue_f.front();
        Point point_j = queue_j.front();
        for (const Point &direction : SearchDirection)
        {
            Point UnitTest_f = point_f + direction;
            if (IsContain(UnitTest_f, r, c))
            {
                // 지나갈수 있는 공간
                if (maze[UnitTest_f.row][UnitTest_f.col] == '.' && buf_f[UnitTest_f.row][UnitTest_f.col] == 0)
                {
                    queue_f.push(UnitTest_f);
                    buf_f[UnitTest_f.row][UnitTest_f.col] = buf_f[point_f.row][point_f.col] + 1;
                }
            }

            Point UnitTest_j = point_j + direction;
            if (IsContain(UnitTest_j, r, c))
            {
                if (maze[UnitTest_j.row][UnitTest_j.col] == '.' && buf_j[UnitTest_j.row][UnitTest_j.col] == 0 && buf_f[UnitTest_j.row][UnitTest_j.col] == 0)
                {
                    queue_j.push(UnitTest_j);
                    buf_j[UnitTest_j.row][UnitTest_j.col] = buf_j[point_j.row][point_j.col] + 1;

                    if (UnitTest_j.row == 0 || UnitTest_j.row == r - 1 || UnitTest_j.col == 0 || UnitTest_j.col == c - 1)
                    {
                        std::cout << buf_j[UnitTest_j.row][UnitTest_j.col];
                        return 0;
                    }
                }
            }
        }
        queue_f.pop();
        queue_j.pop();
    }

    std::cout << "IMPOSSIBLE";

    return 0;
}