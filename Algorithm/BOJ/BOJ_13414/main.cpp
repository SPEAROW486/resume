
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int k, l;

int main()
{
    FASTIO;
    std::cin >> k >> l;

    // k = 수강 가능 인원
    // l = 수강 신청한 인원
    std::unordered_map<std::string, int> map;
    std::vector<std::pair<std::string, int>> v;
    for (int i = 0; i < l; ++i)
    {
        // 순서저장
        std::string tmp;
        std::cin >> tmp;
        map[tmp] = i;
    }

    // 벡터로 복사 후 정렬
    for (const auto &p : map)
    {
        v.push_back(p);
    }

    auto lambda = [](const std::pair<std::string, int> &lhs, const std::pair<std::string, int> &rhs)
    {
        return lhs.second < rhs.second;
    };

    std::sort(v.begin(), v.end(), lambda);
    for (int i = 0; i < std::min(k, static_cast<int>(v.size())); ++i)
    {
        std::cout << v[i].first << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}