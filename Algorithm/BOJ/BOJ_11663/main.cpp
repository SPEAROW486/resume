
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<int> points;

int main()
{
    FASTIO;
    std::cin >> n >> m;
    points.resize(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> points[i];
    }

    // 일단 입력 예제는 오름차순 정렬이 되어 있기는 한데, 다른 입력들도 정렬되서 들어온다는 보장이 없으니까 정렬해줌
    std::sort(points.begin(), points.end());

    for (int i = 0; i < m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        auto lower = std::lower_bound(points.begin(), points.end(), st);
        auto upper = std::upper_bound(points.begin(), points.end(), en);

        std::cout << upper - lower << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}