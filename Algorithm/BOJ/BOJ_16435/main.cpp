
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, l;
std::vector<int> v;
int solve()
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] <= l)
        {
            ++l;
        }
    }
    return l;
}

int main()
{
    FASTIO;

    std::cin >> n >> l;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    std::sort(v.begin(), v.end());
    std::cout << solve() << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}