
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int ans;
int n;

void solve(int a)
{
    if (a == 1)
    {
        return;
    }

    if (a % 2 == 0)
    {
        solve(a / 2);
        solve(a / 2);
        ans += (a / 2) * (a / 2);
    }
    else
    {
        solve(a / 2);
        solve(a - a / 2);
        ans += (a / 2) * (a - a / 2);
    }
}

int main()
{
    FASTIO;
    std::cin >> n;
    solve(n);
    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}