
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 51;
int board[MAX][MAX];

int r, c, t;
std::pair<int, int> air_cleaner_1;
std::pair<int, int> air_cleaner_2;

int air;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 전체적인 접근 방법은 맞았는데 조금씩 미스나서 자력솔이안됨.

// 1회 확산을 시키는 함수
void diffusion()
{
    int copy[MAX][MAX] = {0};

    // 현재 있는 미세먼지를 전부 4방향으로 동시에 확산시켜야함.
    // 그 결과가 한방에 반영되야하니까?
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] > 0)
            {
                int amount = board[i][j] / 5; // 원본을 기준으로 확산양을 계산
                int count = 0;
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    // oob
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                    {
                        continue;
                    }

                    // 공기청정기 위치면
                    if (board[nx][ny] == -1)
                    {
                        continue;
                    }

                    copy[nx][ny] += amount;
                    ++count;
                }
                copy[i][j] += board[i][j] - amount * count;
            }
            else
            {
                copy[i][j] += board[i][j];
            }
        }
    }

    // 원본에 반영
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            board[i][j] = copy[i][j];
        }
    }
}

void clean_up()
{
    for (int i = air_cleaner_1.first - 1; i > 0; --i)
    {
        board[i][0] = board[i - 1][0];
    }
    for (int i = 0; i < c - 1; ++i)
    {
        board[0][i] = board[0][i + 1];
    }
    for (int i = 0; i < air_cleaner_1.first; ++i)
    {
        board[i][c - 1] = board[i + 1][c - 1];
    }
    for (int i = c - 1; i > 1; --i)
    {
        board[air_cleaner_1.first][i] = board[air_cleaner_1.first][i - 1];
    }
    board[air_cleaner_1.first][1] = 0;

    // 아래쪽 공기청정기
    for (int i = air_cleaner_2.first + 1; i < r - 1; ++i)
    {
        board[i][0] = board[i + 1][0];
    }
    for (int i = 0; i < c - 1; ++i)
    {
        board[r - 1][i] = board[r - 1][i + 1];
    }
    for (int i = r - 1; i > air_cleaner_2.first; --i)
    {
        board[i][c - 1] = board[i - 1][c - 1];
    }
    for (int i = c - 1; i > 1; --i)
    {
        board[air_cleaner_2.first][i] = board[air_cleaner_2.first][i - 1];
    }
    board[air_cleaner_2.first][1] = 0;
}

int get_ans()
{
    int ans = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] > 0)
            {
                ans += board[i][j];
            }
        }
    }
    return ans;
}

int main()
{
    FASTIO;
    std::cin >> r >> c >> t;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cin >> board[i][j];
            if (board[i][j] == -1)
            {
                if (air == 0)
                {
                    air_cleaner_1.first = i;
                    air_cleaner_1.second = j;
                    ++air;
                }
                else
                {
                    air_cleaner_2.first = i;
                    air_cleaner_2.second = j;
                }
            }
        }
    }

    while (t--)
    {
        diffusion();
        clean_up();
    }

    std::cout << get_ans() << "\n";

    return 0;
}