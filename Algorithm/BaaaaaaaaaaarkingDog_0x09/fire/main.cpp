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
    int buf[4][4] = {0};

    Point j_init;
    Point f_init;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cin >> maze[i][j];

            if (maze[i][j] == 'J')
            {
                j_init.row = i;
                j_init.col = j;
            }

            if (maze[i][j] == 'F')
            {
                f_init.row = i;
                f_init.col = j;
            }
        }
    }

    // 일단 생각나는거
    // 지훈이용 큐, 불 용 큐를 둔다.
    // 버퍼도 2개를 둔다.
    //

    std::queue<Point> q;

    q.push(j_init);
    q.push(f_init);

    while (!q.empty())
    {
        Point p = q.front();
        for (const Point &direction : SearchDirection)
        {
            Point UnitTest = p + direction;
            if (IsContain(UnitTest, r, c))
            {
                // 지나갈수 있는 공간
                if (maze[UnitTest.row][UnitTest.col] == '.' && buf[UnitTest.row][UnitTest.col] == 0)
                {
                    q.push(UnitTest);
                    buf[UnitTest.row][UnitTest.col] = buf[p.row][p.col] + 1;
                }
            }
        }
        q.pop();
    }

    return 0;
}