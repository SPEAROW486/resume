
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

constexpr int MAX = 100001;
int dp1[MAX]; // 오름차순 - dp1[i] = i번째 요소를 마지막으로 하는 오름차순 구간의 길이?
int dp2[MAX]; // 내림차순

int main()
{
    // FASTIO;

    std::cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    // 1번째 요소가 마지막이면 당연히 길이는 1
    dp1[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (v[i - 1] <= v[i])
        {
            dp1[i] = dp1[i - 1] + 1;
        }
        else
        {
            dp1[i] = 1;
        }
    }

    dp2[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (v[i - 1] >= v[i])
        {
            dp2[i] = dp2[i - 1] + 1;
        }
        else
        {
            dp2[i] = 1;
        }
    }

    std::cout << std::max(*std::max_element(dp1, dp1 + MAX), *std::max_element(dp2, dp2 + MAX)) << "\n";
    return 0;
}