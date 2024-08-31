#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<std::pair<int, std::string>> ranks;

std::string search(int p)
{
    int left = 0;
    int right = ranks.size() - 1;
    std::string result;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (ranks[mid].first >= p)
        {
            result = ranks[mid].second;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

int main()
{
    FASTIO;

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::string rank;
        int power;
        std::cin >> rank >> power;

        // 기존 ranks에 push_back 사용을 유지
        ranks.push_back({power, rank});
    }

    for (int i = 0; i < m; ++i)
    {
        int power;
        std::cin >> power;
        std::cout << search(power) << "\n";
    }

    return 0;
}
