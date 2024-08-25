
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

int distanceSquared(std::pair<int, int> a, std::pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    FASTIO;
    std::cin >> tc;
    while (tc--)
    {
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < 4; ++i)
        {
            int x, y;
            std::cin >> x >> y;

            v.push_back({x, y});
        }

        std::vector<int> distances;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j)
            {
                distances.push_back(distanceSquared(v[i], v[j]));
            }
        }
        std::sort(distances.begin(), distances.end());

        // 정사각형 확인: 변의 길이 4개와 대각선의 길이 2개가 같아야 함
        if (distances[0] > 0 &&
            distances[0] == distances[1] &&
            distances[1] == distances[2] &&
            distances[2] == distances[3] &&
            distances[4] == distances[5])
        {
            std::cout << 1 << "\n"; // 정사각형 가능
        }
        else
        {
            std::cout << 0 << "\n"; // 정사각형 불가능
        }
    }
    // int nn;
    // std::cin >> nn;
    return 0;
}