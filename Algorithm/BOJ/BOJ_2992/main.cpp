
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int solve(int number)
{
    std::vector<int> v;

    int tmp = number;
    while (tmp > 0)
    {
        v.push_back(tmp % 10);
        tmp /= 10;
    }

    int ans = 10000000;
    std::sort(v.begin(), v.end());
    do
    {
        int n = 0;
        int bias = pow(10, v.size() - 1);
        for (int i = 0; i < v.size(); ++i)
        {
            n += v[i] * bias;
            bias = std::max(bias / 10, 1);
        }

        if (n > number)
        {
            ans = std::min(ans, n);
        }
    } while (std::next_permutation(v.begin(), v.end()));

    return ans >= 10000000 ? 0 : ans;
}

int main()
{
    FASTIO;

    int n;
    std::cin >> n;
    std::cout << solve(n) << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
