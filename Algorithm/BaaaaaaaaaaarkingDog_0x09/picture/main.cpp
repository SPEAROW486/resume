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

bool IsWithInRange(const Point &p, const int row_max, const int col_max)
{

    for (const Point &elem : SearchDirection)
    {
        Point UnitTest = p + elem;
        if (UnitTest.row < 0 || UnitTest.row >= row_max)
        {
            return false;
        }
        if (UnitTest.col < 0 || UnitTest.col >= col_max)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int buf[500][500] = {0};
    bool visit[500][500] = {0};

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            std::cin >> buf[row][col];
        }
    }

    int count = 0;
    int size = 0;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (buf[row][col] == 0 || visit[row][col])
            {
                continue;
            }

            std::queue<Point> q;
            q.push(Point(row, col));
            visit[row][col] = true;
            ++count;

            int temp = 0;
            while (!q.empty())
            {
                const Point p = q.front();
                for (const Point &elem : SearchDirection)
                {
                    Point UnitTest = p + elem;
                    if ((UnitTest.row >= 0 && UnitTest.row < n) && (UnitTest.col >= 0 && UnitTest.col < m))
                    {
                        if (buf[UnitTest.row][UnitTest.col] == 1 && !visit[UnitTest.row][UnitTest.col])
                        {
                            q.push(UnitTest);
                            visit[UnitTest.row][UnitTest.col] = true;
                        }
                    }
                }
                q.pop();
                ++temp;
            }
            size = std::max(size, temp);
        }
    }
    std::cout << count << std::endl
              << size;
    return 0;
}