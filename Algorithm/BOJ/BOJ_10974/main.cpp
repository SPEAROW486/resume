
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
        v.push_back(i + 1);
    }

    do
    {
        for (int i = 0; i < v.size(); ++i)
        {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    } while (std::next_permutation(v.begin(), v.end()));

    // int nn;
    // std::cin >> nn;
    return 0;
}