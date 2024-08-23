
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
    for (int i = 0; i < n; ++i)
    {
        int pos, clr;
        std::cin >> pos >> clr;
        v.push_back({clr, pos});
    }

    // 색깔이 같은 가장 가까운 다른 점을 찾는다.
    // 찾은 점 -현재 점 뺴면 길이가 나옴
    // 그것들의 합.
    std::sort(v.begin(), v.end());

    // 0번쨰면 우측만 비교
    // n번째면 좌측만 비교
    // 사이에있으면 둘다 비교해야됨.

    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == 0)
        {
            ans += (v[i].first == v[i + 1].first) ? v[i + 1].second - v[i].second : 0;
        }
        else if (i == v.size() - 1)
        {
            ans += (v[i].first == v[i - 1].first) ? v[i].second - v[i - 1].second : 0;
        }
        else
        {
            int left = (v[i].first == v[i - 1].first) ? v[i].second - v[i - 1].second : INT_MAX;
            int right = (v[i].first == v[i + 1].first) ? v[i + 1].second - v[i].second : INT_MAX;

            int min = std::min(left, right);
            if (min != INT_MAX)
            {
                ans += min;
            }
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}