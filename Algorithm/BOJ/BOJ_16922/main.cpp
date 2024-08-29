
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001; // 50을 20번 고르면 1000이니까
int n, ans;
int roma[] = {1, 5, 10, 50};
bool visit[MAX];

void solve(int idx, int depth, int total)
{
    // 횟수는 depth가 결정
    // 종류는 for문이 결정?
    if (depth == n)
    {
        if (!visit[total])
        {
            visit[total] = true;
            ++ans;
        }
    }
    else
    {
        // 0부터 시작해서 n번만큼
        // 0,0,0,0
        // 0,0,0,1
        // 0,0,0,2
        // 0,0,0,3

        // 0,0,1,0

        // 이런식?
        // 시작점을 바꿔서 중복 조합을 허용
        for (int i = idx; i < 4; ++i)
        {
            solve(i, depth + 1, total + roma[i]);
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n;
    solve(0, 0, 0);
    // 조합으로 하자니 중복된게 나와버리고..
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}