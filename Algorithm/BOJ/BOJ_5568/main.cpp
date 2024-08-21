
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
std::vector<int> v;

int solve()
{
    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);

    std::set<int> set;
    do
    {
        std::string s;
        for (int i = 0; i < k; ++i)
        {
            s += std::to_string(v[indices[i]]);
        }
        int number = std::stoi(s);
        set.insert(number);
    } while (std::next_permutation(indices.begin(), indices.end()));

    return set.size();
}

int main()
{
    // FASTIO;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cout << solve();

    int nn;
    std::cin >> nn;
    return 0;
}