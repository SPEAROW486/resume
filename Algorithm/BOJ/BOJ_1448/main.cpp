
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
int ans = -1;
std::vector<int> vec;

void solve2()
{
    for (int i = 2; i < vec.size(); ++i)
    {
        int a = vec[i - 2];
        int b = vec[i - 1];
        int c = vec[i];

        if (a + b > c && a + c > b && b + c > a)
        {
            ans = std::max(ans, a + b + c);
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
    }
    std::sort(vec.begin(), vec.end());

    solve2();
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}