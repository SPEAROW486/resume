
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
int ans;
std::vector<int> v;
void solve(int num)
{
    if (n < num)
    {
        return;
    }

    ans = std::max(ans, num);
    num *= 10;
    for (int i = 0; i < v.size(); ++i)
    {
        solve(num + v[i]);
    }
}

int main()
{
    FASTIO;

    std::cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    solve(0);
    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}