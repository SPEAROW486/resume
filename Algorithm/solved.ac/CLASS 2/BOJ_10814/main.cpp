
#include <bits/stdc++.h>

int n;

std::vector<std::pair<int, std::string>> v;

bool pred(const std::pair<int, std::string> &lhs, const std::pair<int, std::string> &rhs)
{
    int lage, rage;

    lage = lhs.first;
    rage = rhs.first;

    return lage < rage;
}

int main()
{

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int age;
        std::string name;
        std::cin >> age >> name;

        v.push_back({age, name});
    }

    std::stable_sort(v.begin(), v.end(), pred);

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i].first << " " << v[i].second << "\n";
    }

    int nn;
    std::cin >> nn;

    return 0;
}