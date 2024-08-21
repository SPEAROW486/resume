
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

struct TrafficLight
{
    int pos = 0;
    int red = 0;
    int green = 0;
};

int n, l;
std::vector<TrafficLight> v;
int main()
{
    FASTIO;
    std::cin >> n >> l;

    for (int i = 0; i < n; ++i)
    {
        int pos, red, green;
        std::cin >> pos >> red >> green;
        v.push_back({pos, red, green});
    }

    int time = 0;
    int current = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int travle = v[i].pos - current;
        time += travle;

        current = v[i].pos;

        int cycle = v[i].red + v[i].green;
        bool wait = time % cycle < v[i].red;
        if (wait)
        {
            time += v[i].red - (time % cycle);
        }
    }

    time += l - current;
    std::cout << time;

    // int nn;
    // std::cin >> nn;
    return 0;
}