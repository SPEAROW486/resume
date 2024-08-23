
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int main()
{
    // FASTIO;
    std::cin >> n;
    for (int i = 0; i < 2 * n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    int lidx = 0;
    int ridx = v.size() - 1;

    int min = INT_MAX;
    for (int i = 0; i < v.size() / 2; ++i)
    {
        min = std::min(min, v[lidx++] + v[ridx--]);
    }

    std::cout << min;

    int nn;
    std::cin >> nn;
    return 0;
}