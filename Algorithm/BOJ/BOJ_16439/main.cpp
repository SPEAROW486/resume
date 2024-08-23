
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
int ans;
std::vector<std::vector<int>> v;
int selected[3];

void solve(int idx, int cnt)
{
    if (cnt != -1)
    {
        selected[cnt] = idx;
    }

    if (cnt == 2)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int score = 0;
            for (int j = 0; j < 3; ++j)
            {
                score = std::max(score, v[i][selected[j]]);
            }
            sum += score;
        }
        ans = std::max(ans, sum);
        return;
    }

    // 0 1 2
    // 0 1 3
    // 0 1 4
    // 이런식으로 조합을 확인해나감.
    for (int i = idx; i < m; ++i)
    {
        solve(i + 1, cnt + 1);
    }
}

int main()
{
    // FASTIO;
    std::cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int tmp;
            std::cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    solve(-1, -1);
    std::cout << ans << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}