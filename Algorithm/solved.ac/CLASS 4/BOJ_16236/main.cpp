
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 21;

int board[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int size = 2;
int count;
int n;
int ans;
int sx, sy;
// 조건이 많아도, n이 엄청 작고 메모리 제한도 커서 이것저것 돌려봐도 ?

// 1. bfs부터 짠다. (주체는 상어겟지?)
// 2. 물고기 먹는거..

// 1. 더이상 먹을수있는 물고기가 공간에 없는지 어케암 ? -> 이건 2,3번 행동을 더이상 할수 없을떄가 되겠지
// 2. 먹을 수 있는 물고기가 1개면 그걸 먹으러감.
// 3. 먹을 수 있는 물고기가 1마리 이상이면 가장 가까운거 [가장위,가장왼쪽];

bool can_eat(int x, int y)
{
    return board[x][y] > 0 && board[x][y] < size;
}

void compute_size()
{
    if (count >= size)
    {
        count -= size;
        ++size;
    }
}

bool bfs(int x, int y)
{
    bool visit[MAX][MAX];
    std::fill(&visit[0][0], &visit[MAX - 1][MAX], false);

    int dist[MAX][MAX];
    std::fill(&dist[0][0], &dist[MAX - 1][MAX], 0);

    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    // dist, x, y
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
    int min_distance = INT_MAX;

    compute_size();
    while (!q.empty())
    {
        const std::pair<int, int> front = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = front.first + dx[dir];
            int ny = front.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }

            if (visit[nx][ny])
            {
                continue;
            }

            // 지나가는 조건
            if (board[nx][ny] > size)
            {
                continue;
            }

            q.push({nx, ny});
            visit[nx][ny] = true;
            dist[nx][ny] = dist[front.first][front.second] + 1;

            if (can_eat(nx, ny))
            {
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }

    if (pq.empty())
    {
        return false;
    }

    // 1번에 1마리만
    // 먹고 나면 먹은 자리로 이동함 ㅅㅂ
    if (!pq.empty())
    {
        int distance, fx, fy;
        std::tie(distance, fx, fy) = pq.top();
        sx = fx;
        sy = fy;
        board[sx][sy] = 0;
        ++count;
        ans += distance;
    }

    return true;
}

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 9)
            {
                sx = i;
                sy = j;

                // 한번 먹으면 기존 위치에 상어가 없으니까 0으로 바꿔줘야하는듯..
                // 9라는 입력값은 상어의 위치를 알려주는 플래그지 사실상 탐색에서의 9라는 값은 사용하지 않기 떄문에?
                board[i][j] = 0;
            }
        }
    }

    while (true)
    {
        if (!bfs(sx, sy))
        {
            break;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}