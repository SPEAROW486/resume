
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

// 점수 , 국가 번호, 학생 번호
std::vector<std::tuple<int, int, int>> v;
std::vector<int> counts;

int main()
{
    FASTIO;
    std::cin >> n;

    int nation_max = 0;
    for (int i = 0; i < n; ++i)
    {
        int nation, number, score;

        std::cin >> nation >> number >> score;

        v.push_back({score, nation, number});
        nation_max = std::max(nation_max, nation);
    }

    counts.resize(nation_max + 1, 0);
    std::sort(v.begin(), v.end(), std::greater<>());
    int tmp = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int score, nation, number;
        std::tie(score, nation, number) = v[i];

        if (counts[nation]++ < 2)
        {
            std::cout << nation << " " << number << "\n";
            if (++tmp >= 3)
            {
                break;
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}