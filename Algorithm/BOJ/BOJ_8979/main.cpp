#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;

struct Country
{
    int number;
    int gold;
    int silver;
    int bronze;
};

bool compare(const Country &a, const Country &b)
{
    if (a.gold != b.gold)
        return a.gold > b.gold;
    if (a.silver != b.silver)
        return a.silver > b.silver;
    return a.bronze > b.bronze;
}

int main()
{
    FASTIO;
    std::cin >> n >> k;

    std::vector<Country> countries(n);

    for (int i = 0; i < n; ++i)
    {
        int number, g, s, b;
        std::cin >> number >> g >> s >> b;
        countries[i] = {number, g, s, b};
    }

    std::sort(countries.begin(), countries.end(), compare);

    int rank = 1;
    int previous_rank = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && (countries[i].gold != countries[i - 1].gold ||
                      countries[i].silver != countries[i - 1].silver ||
                      countries[i].bronze != countries[i - 1].bronze))
        {
            rank = i + 1;
        }
        if (countries[i].number == k)
        {
            previous_rank = rank;
            break;
        }
    }

    std::cout << previous_rank << "\n";

    int nn;
    std::cin >> nn;

    return 0;
}
