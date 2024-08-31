#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int WEIGHT = 500;
constexpr int MAX = 8;
int n, k;
std::vector<int> v;
bool visit[MAX];
int ans;
void solve(int depth, int w)
{
    if (w < WEIGHT)
    {
        return;
    }

    if (depth == n)
    {
        ++ans;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (visit[i])
            {
                continue;
            }

            visit[i] = true;
            solve(depth + 1, w + v[i] - k);
            visit[i] = false;
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    solve(0, WEIGHT);
    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
