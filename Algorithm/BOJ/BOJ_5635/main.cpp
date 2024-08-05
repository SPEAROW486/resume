
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::tuple<std::string, int, int, int>> v;

bool cmp(const std::tuple<std::string, int, int, int> &lhs, const std::tuple<std::string, int, int, int> &rhs)
{
    std::string ls;
    int lyy;
    int lmm;
    int ldd;

    std::string rs;
    int ryy;
    int rmm;
    int rdd;

    std::tie(ls, lyy, lmm, ldd) = lhs;
    std::tie(rs, ryy, rmm, rdd) = rhs;

    if (ryy == lyy)
    {
        if (rmm == lmm)
        {
            return rdd > ldd;
        }
        else
        {
            return rmm > lmm;
        }
    }

    return ryy > lyy;
}

int main()
{
    // FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        int dd, mm, yy;

        std::cin >> s;
        std::cin >> dd >> mm >> yy;

        v.push_back({s, yy, mm, dd});
    }

    std::sort(v.begin(), v.end(), cmp);

    std::cout << std::get<0>(v[n - 1]) << "\n";
    std::cout << std::get<0>(v[0]) << "\n";

    int nn;
    std::cin >> nn;
    return 0;
}