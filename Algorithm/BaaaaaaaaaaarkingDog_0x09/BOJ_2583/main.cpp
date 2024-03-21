
#include <bits/stdc++.h>

constexpr int MAX = 101;
int board[MAX][MAX];

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#define X first
#define Y second

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n, k;
    std::cin >> m >> n >> k;

    for (int i = 0; i < k; ++i)
    {
        int left_bottom_x, left_bottom_y;
        int right_top_x, right_top_y;

        std::cin >> left_bottom_x >> left_bottom_y >> right_top_x >> right_top_y;

        for (int row = m - right_top_y; row < m - left_bottom_y; ++row)
        {
            for (int col = left_bottom_x; col < right_top_x; ++col)
            {
                board[row][col] = -1;
            }
        }
    }

    // 보드 기본값 0
    // 직사각형 영역은 -1
    // 방문한곳은 1
    std::queue<std::pair<int, int>> q;

    // set으로 하면 중복을 허용하지 않아서 같은 넓이를 가진 영역이 있을때 틀렸음.
    std::vector<int> v;
    int count = 0;
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < m; ++i)
        {
            // -1이거나 1이면 직사각형 범위거나 이미 방문한곳이니까 패스
            if (board[i][j] != 0)
            {
                continue;
            }

            board[i][j] = 1; // 방문 처리
            q.push({i, j});
            int extent = 1;
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    {
                        continue;
                    }

                    // 0이 아니면 직사각형 영역이거나 이미 방문한 곳
                    if (board[nx][ny] != 0)
                    {
                        continue;
                    }

                    board[nx][ny] = 1;
                    q.push({nx, ny});
                    ++extent;
                }
            }
            ++count;
            v.push_back(extent);
        }
    }

    std::cout << count << "\n";
    std::sort(v.begin(), v.end());

    for (auto ex : v)
    {
        std::cout << ex << " ";
    }
    return 0;
}