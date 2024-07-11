
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int BLANK = 0;
constexpr int WALL = 1;
constexpr int VIRUS = 2;
constexpr int MAX = 9;

std::vector<std::pair<int, int>> blanks;
std::vector<std::pair<int, int>> viruses;

int board[MAX][MAX];
int copy_board[MAX][MAX];
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = INT_MIN;

std::vector<std::vector<std::pair<int, int>>> get_combinations()
{
    // 빈 공간에 벽 3개를 세울 수 있는 모든 조합을 구하는 함수
    std::vector<std::vector<std::pair<int, int>>> combinations;

    std::vector<bool> v(blanks.size());
    std::fill(v.end() - 3, v.end(), true); // 벽 3개를 세울 위치만 트루로

    do
    {
        std::vector<std::pair<int, int>> combine;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i])
            {
                combine.push_back(blanks[i]);
            }
        }
        // combine에는 3개의 조합된 위치가 푸쉬되고
        // 조합 단위로 최종 벡터에 푸쉬됨.
        combinations.push_back(combine);
    } while (std::next_permutation(v.begin(), v.end()));

    return combinations;
}

void bfs_virus()
{
    bool visit[MAX][MAX];
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            copy_board[i][j] = board[i][j];
        }
    }

    std::queue<std::pair<int, int>> q;
    for (const std::pair<int, int> &v : viruses)
    {
        const int &x = v.first;
        const int &y = v.second;
        if (visit[x][y])
        {
            continue;
        }

        q.push({x, y});
        visit[x][y] = true;

        while (!q.empty())
        {
            const std::pair<int, int> front = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = front.first + dx[dir];
                int ny = front.second + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }

                if (visit[nx][ny])
                {
                    continue;
                }

                if (copy_board[nx][ny] != BLANK)
                {
                    continue;
                }

                copy_board[nx][ny] = VIRUS;
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

void bfs_safety()
{
    // 공간이 분리되서 안전영역이 여러개가 나올수도 있는데
    // 예제를 보니 그 영역들의 총 합임.
    // 영역중 가장큰거찾는게아니라
    bool visit[MAX][MAX];
    memset(visit, false, sizeof(visit));

    std::queue<std::pair<int, int>> q;

    int safety = 0;
    for (const std::pair<int, int> &b : blanks)
    {
        const int &x = b.first;
        const int &y = b.second;

        if (visit[x][y])
        {
            continue;
        }

        if (copy_board[x][y] != BLANK)
        {
            continue;
        }

        q.push({x, y});
        visit[x][y] = true;
        ++safety; // 첫 방문시에 카운트 올려주는걸 깜빡해서 엄청 헤맴
        while (!q.empty())
        {
            const std::pair<int, int> front = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = front.first + dx[dir];
                int ny = front.second + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }

                if (visit[nx][ny])
                {
                    continue;
                }

                if (copy_board[nx][ny] != BLANK)
                {
                    continue;
                }

                q.push({nx, ny});
                visit[nx][ny] = true;
                ++safety;
            }
        }
    }
    result = std::max(result, safety);
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    // 1. 벽을 3개 세운다.
    // 2. 바이러스의 BFS를 돌린다.
    // 3. 안전영역의 BFS를 돌린다.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];

            if (board[i][j] == BLANK)
            {
                blanks.push_back({i, j});
            }

            if (board[i][j] == VIRUS)
            {
                viruses.push_back({i, j});
            }
        }
    }

    std::vector<std::vector<std::pair<int, int>>> combinations = get_combinations();
    for (int i = 0; i < combinations.size(); ++i)
    {
        const std::vector<std::pair<int, int>> &candidate = combinations[i];
        // 벽 세우기
        for (const std::pair<int, int> &pos : candidate)
        {
            const int &x = pos.first;
            const int &y = pos.second;
            board[x][y] = WALL;
        }

        bfs_virus();
        bfs_safety();

        // 복구
        for (const std::pair<int, int> &pos : candidate)
        {
            const int &x = pos.first;
            const int &y = pos.second;
            board[x][y] = BLANK;
        }
    }
    std::cout << result;

    return 0;
}