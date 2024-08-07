
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
bool isAscending(const std::vector<std::string> &vec)
{
    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i - 1] > vec[i])
        {
            return false;
        }
    }
    return true;
}

bool isDescending(const std::vector<std::string> &vec)
{
    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i - 1] < vec[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FASTIO;
    std::cin >> n;

    std::vector<std::string> v;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        v.push_back(s);
    }

    bool ascending = isAscending(v);
    bool descending = isDescending(v);

    if (ascending)
    {
        std::cout << "INCREASING\n";
    }
    else if (descending)
    {
        std::cout << "DECREASING\n";
    }
    else
    {
        std::cout << "NEITHER\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}