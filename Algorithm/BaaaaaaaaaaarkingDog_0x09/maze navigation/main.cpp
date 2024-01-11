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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    char buf[100][100] = {0};
    int path[100][100] = {0};
    for (int row = 0; row < n; ++row)
    {
        std::string num;
        std::cin >> num;

        for (int i = 0; i < m; ++i)
        {
            buf[row][i] = num[i];
        }
    }

    std::queue<Point> q;
    q.push(Point(0, 0));
    path[0][0] = 1;

    while (!q.empty())
    {
        const Point p = q.front();
        for (const Point &elem : SearchDirection)
        {
            Point UnitTest = p + elem;
            if ((UnitTest.row >= 0 && UnitTest.row < n) && (UnitTest.col >= 0 && UnitTest.col < m))
            {
                if (buf[UnitTest.row][UnitTest.col] == '1' && path[UnitTest.row][UnitTest.col] == 0)
                {
                    q.push(UnitTest);
                    path[UnitTest.row][UnitTest.col] = path[p.row][p.col] + 1;
                    if (UnitTest.row == n - 1 && UnitTest.col == m - 1)
                    {
                        std::cout << path[n - 1][m - 1];
                        return 0;
                    }
                }
            }
        }
        q.pop();
    }

    return 0;
}