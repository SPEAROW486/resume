
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::pair<int, int>> v;

int main()
{
    FASTIO;
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
    }

    int total_distance = 0;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        total_distance += abs(v[i + 1].first - v[i].first) + abs(v[i + 1].second - v[i].second);
    }

    int max_reduced = 0;
    for (int i = 1; i < v.size() - 1; ++i)
    {
        // 세 지점의 거리 합산
        int original = abs(v[i - 1].first - v[i].first) + abs(v[i - 1].second - v[i].second) +
                       abs(v[i].first - v[i + 1].first) + abs(v[i].second - v[i + 1].second);

        // 중간 지점을 건너 뛴 거리
        int reduced = abs(v[i - 1].first - v[i + 1].first) + abs(v[i - 1].second - v[i + 1].second);
        max_reduced = std::max(max_reduced, original - reduced);
    }

    int answer = total_distance - max_reduced;
    std::cout << answer << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}