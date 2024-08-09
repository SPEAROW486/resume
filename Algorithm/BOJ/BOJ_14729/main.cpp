
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::vector<double> v;
int n;

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        double tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    std::cout << std::fixed;
    std::cout.precision(3);

    for (int i = 0; i < 7; ++i)
    {
        std::cout << v[i] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}