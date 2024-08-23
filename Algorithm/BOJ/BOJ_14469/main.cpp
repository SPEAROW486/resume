
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::pair<int, int>> v;
int main()
{
    // FASTIO;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        v.push_back({st, en});
    }

    std::sort(v.begin(), v.end());

    int current_time = 0;

    for (int i = 0; i < n; ++i)
    {
        int arrival = v[i].first;
        int duration = v[i].second;

        if (current_time < arrival)
        {
            current_time = arrival;
        }

        current_time += duration;
    }

    std::cout << current_time;

    int nn;
    std::cin >> nn;

    return 0;
}