
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end(), std::greater<int>());

    std::vector<std::pair<int, int>> v2;
    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        v2.push_back({i + 1, v[i]});
    }

    // 일단 묘목개수만큼 날짜까 소요되는건 맞음.
    // 근데 언제 심었냐에 따라서 며칠남았냐가 달라지니까
    for (int i = 0; i < v2.size(); ++i)
    {
        int day = v2[i].first;
        int remain = v2[i].second;

        v2[i].second = remain - (n - day);
    }

    auto cmp = [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
    {
        return lhs.second < rhs.second;
    };

    auto max = std::max_element(v2.begin(), v2.end(), cmp);

    std::cout << n + max->second + 1 << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}