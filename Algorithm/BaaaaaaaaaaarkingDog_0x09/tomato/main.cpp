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

    int m, n;
    std::cin >> m >> n;

    int tomato[1000][1000] = {0};
    int buf[1000][1000] = {0};

    constexpr int is_ripe = 1;
    constexpr int is_not_ripe = 0;
    constexpr int is_empty = -1;

    bool is_all_tomato_Riped = true;
    int count_riped = 0;
    int total_tomatos = 0;

    std::queue<Point> q;

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            std::cin >> tomato[row][col];
            if (tomato[row][col] == is_ripe || tomato[row][col] == is_not_ripe)
            {
                is_all_tomato_Riped &= tomato[row][col] == is_ripe;
            }

            if (tomato[row][col] == is_ripe)
            {
                ++count_riped;
                q.push(Point(row, col));
            }

            if (tomato[row][col] == is_ripe || tomato[row][col] == is_not_ripe)
            {
                ++total_tomatos;
            }
        }
    }

    if (is_all_tomato_Riped)
    {
        std::cout << 0;
        return 0;
    }

    int minimum_date = 0;

    while (!q.empty())
    {
        const Point p = q.front();
        for (const Point &elem : SearchDirection)
        {
            Point UnitTest = p + elem;
            if ((UnitTest.row >= 0 && UnitTest.row < n) && (UnitTest.col >= 0 && UnitTest.col < m))
            {
                if (tomato[UnitTest.row][UnitTest.col] == is_not_ripe && buf[UnitTest.row][UnitTest.col] == 0)
                {
                    q.push(UnitTest);
                    buf[UnitTest.row][UnitTest.col] = buf[p.row][p.col] + 1;
                    minimum_date = std::max(minimum_date, buf[UnitTest.row][UnitTest.col]);
                    ++count_riped;
                }
            }
        }
        q.pop();
    }

    if (total_tomatos != count_riped)
    {
        std::cout << -1;
        return 0;
    }

    std::cout << minimum_date;

    return 0;
}