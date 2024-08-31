#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 26215
// 그냥 특별한 풀이가 생각나진 않고 정렬하고 그리디..?

constexpr int DAY_TIME = 1440;
int n;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end(), std::greater<>());

    int time = 0;
    while (!v.empty())
    {
        int first = v[0];
        v.erase(v.begin());

        int second = 0;
        if (!v.empty())
        {
            second = v[0];
            v.erase(v.begin());
        }

        if (first > 0)
        {
            --first;
        }

        if (second > 0)
        {
            --second;
        }

        if (first > 0)
        {
            v.push_back(first);
        }

        if (second > 0)
        {
            v.push_back(second);
        }

        std::sort(v.begin(), v.end(), std::greater<>());
        ++time;
    }

    time = time > DAY_TIME ? -1 : time;
    std::cout << time << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}
