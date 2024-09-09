#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 10819

int n;
std::vector<int> v;

int solve()
{
    int ans = 0;

    std::sort(v.begin(), v.end());
    do
    {
        int sum = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            sum += abs(v[i] - v[i + 1]);
        }
        ans = std::max(ans, sum);
    } while (std::next_permutation(v.begin(), v.end()));

    return ans;
}

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cout << solve() << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
