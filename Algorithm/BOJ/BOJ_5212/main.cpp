#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 5212

constexpr int MAX = 10;
int r, c;
std::vector<std::string> v;

static int dx[4] = {-1, 1, 0, 0};
static int dy[4] = {0, 0, -1, 1};

bool visit[MAX][MAX];

int main()
{
    FASTIO;
    std::cin >> r >> c;

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < r; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(tmp);

        // 섬 위치를 미리 큐에 다 넣어둠.
        for (int j = 0; j < tmp.length(); ++j)
        {
            if (tmp[j] == 'X')
            {
                q.push({i, j});
            }
        }
    }

    std::vector<std::string> ans(v);
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        // 인접한 타일에 바다가 얼마나 있는지 체크
        int sea = 0;
        for (int d = 0; d < 4; ++d)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                ++sea;
                continue;
            }

            if (v[nx][ny] == 'X')
            {
                continue;
            }

            ++sea;
        }

        if (sea >= 3)
        {
            // 여기서 원본을 바로 수정해버리며 안되니 복사본을 수정
            ans[cx][cy] = '.';
        }
    }

    // 각 행을 돌면서 섬이 나오는 가장 작은 인덱스, 가장 큰 인덱스를 찾아야함.
    int min_col_idx = 1e9;
    int max_col_idx = 0;
    int min_row_idx = 1e9;
    int max_row_idx = 0;

    for (int i = 0; i < ans.size(); ++i)
    {
        std::string s = ans[i];
        bool has_land = false; // 해당 행에 섬이 있는지 체크
        for (int j = 0; j < s.length(); ++j)
        {
            if (s[j] == 'X')
            {
                has_land = true;
                min_col_idx = std::min(min_col_idx, j);
                max_col_idx = std::max(max_col_idx, j);
            }
        }

        if (has_land)
        {
            min_row_idx = std::min(min_row_idx, i);
            max_row_idx = std::max(max_row_idx, i);
        }
    }

    // 최소 행과 최대 행을 기준으로만 출력
    for (int i = min_row_idx; i <= max_row_idx; ++i)
    {
        std::string s = ans[i];
        for (int j = min_col_idx; j <= max_col_idx; ++j)
        {
            std::cout << s[j];
        }
        std::cout << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
