#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    std::string s;
    std::unordered_map<std::string, int> cnt;
    int total = 0;

    while (std::getline(std::cin, s))
    {
        ++cnt[s];
        ++total;
    }

    std::cout << std::fixed << std::setprecision(4);

    std::vector<std::pair<std::string, int>> sorted(cnt.begin(), cnt.end());
    std::sort(sorted.begin(), sorted.end());

    for (const auto &p : sorted)
    {
        double percentage = (p.second * 100.0) / total;
        std::cout << p.first << " " << percentage << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
