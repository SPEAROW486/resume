
#include <bits/stdc++.h>

constexpr int MAX = 1001;
std::string buf[MAX];

std::vector<std::tuple<int, int, int, std::string>> v;

bool pred(const std::tuple<int, int, int, std::string> &lhs, const std::tuple<int, int, int, std::string> &rhs)
{
    int lk, le, lm;
    int rk, re, rm;
    std::string ls, rs;

    std::tie(lk, le, lm, ls) = lhs;
    std::tie(rk, re, rm, rs) = rhs;

    if (lk == rk && le == re && lm == rm)
    {
        return ls < rs;
    }
    else if (lk == rk && le == re)
    {
        return lm > rm;
    }
    else if (lk == rk)
    {
        return le < re;
    }
    return lk > rk;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string name;
        int korean, english, math;

        std::cin >> name >> korean >> english >> math;

        v.push_back({korean, english, math, name});
    }

    std::sort(v.begin(), v.end(), pred);

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << std::get<3>(v[i]) << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}