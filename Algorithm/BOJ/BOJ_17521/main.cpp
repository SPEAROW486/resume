
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
long long w;
std::vector<int> v;

int main()
{
    // FASTIO;
    std::cin >> n >> w;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    long long stack = 0;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i] < v[i + 1])
        {
            stack = w / v[i];
            w %= v[i];
            w += v[i + 1] * stack;
        }
    }
    std::cout << w;

    int nn;
    std::cin >> nn;
    return 0;
}