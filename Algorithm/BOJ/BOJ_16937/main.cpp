
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int h, w, n;
std::vector<std::tuple<int, int, int>> stickers;
bool visited[100];
std::pair<int, int> stk[2];
int answer;

void check()
{
    // 가로 2개
    if (std::max(stk[0].first, stk[1].first) <= h && (stk[0].second + stk[1].second) <= w)
    {
        answer = std::max(answer, stk[0].first * stk[0].second + stk[1].first * stk[1].second);
    }
    // 세로 2개
    if ((stk[0].first + stk[1].first) <= h && std::max(stk[0].second, stk[1].second) <= w)
    {
        answer = std::max(answer, stk[0].first * stk[0].second + stk[1].first * stk[1].second);
    }
}

void solve(int idx, int cnt, int depth)
{
    if (depth == 2)
    {
        check();
        return;
    }
    else
    {
        for (int i = idx; i < cnt; ++i)
        {
            int r, c, n;
            std::tie(r, c, n) = stickers[i];
            if (visited[n])
            {
                continue;
            }

            stk[depth] = {r, c};
            visited[n] = true;
            solve(idx + 1, cnt, depth + 1);
            visited[n] = false;
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> h >> w >> n;
    for (int i = 0; i < n; i++)
    {
        int r, c;
        std::cin >> r >> c;
        stickers.push_back({r, c, i});

        // 스티커 돌리기
        if (r != c)
        {
            stickers.push_back({c, r, i});
        }
    }
    solve(0, stickers.size(), 0);
    std::cout << answer << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}