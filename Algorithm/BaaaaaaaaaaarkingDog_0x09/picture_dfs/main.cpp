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

constexpr int row_max = 500;
constexpr int col_max = 500;
int buf[row_max][col_max] = {0};
bool visit[row_max][col_max] = {0};

// 상하좌우
static Point SearchDirection[4] = {
    Point(-1, 0),
    Point(1, 0),
    Point(0, -1),
    Point(0, 1)};

int Recursive(const Point &p)
{
    int result = 1;
    for (const Point &elem : SearchDirection)
    {
        Point UnitTest = p + elem;
        if ((UnitTest.row >= 0 && UnitTest.row < row_max) && (UnitTest.col >= 0 && UnitTest.col < col_max))
        {
            if (buf[UnitTest.row][UnitTest.col] == 1 && !visit[UnitTest.row][UnitTest.col])
            {
                visit[UnitTest.row][UnitTest.col] = true;
                result += Recursive(UnitTest);
            }
        }
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

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

            visit[row][col] = true;
            ++count;

            int temp = Recursive(Point(row, col));
            size = std::max(size, temp);
        }
    }
    std::cout << count << std::endl
              << size;
    return 0;
}