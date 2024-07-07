
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 21;
constexpr int ALPHABET = 26;

bool visit[ALPHABET];
char board[MAX][MAX];

int r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;

void dfs(int x, int y, int depth)
{
    ans = std::max(ans, depth);
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= r || nx < 0 || ny >= c || ny < 0)
        {
            continue;
        }

        if (visit[board[nx][ny] - 'A'])
        {
            continue;
        }

        visit[board[nx][ny] - 'A'] = true;
        dfs(nx, ny, depth + 1);
        visit[board[nx][ny] - 'A'] = false;
    }
}

int main()
{
    FASTIO;
    std::cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < c; ++j)
        {
            board[i][j] = s[j];
        }
    }

    visit[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}