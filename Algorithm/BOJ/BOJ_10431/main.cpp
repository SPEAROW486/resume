
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc, n;

int solve(std::vector<int> &vec)
{
    int count = 0;

    for (int i = 1; i < vec.size(); ++i)
    {
        int current = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > current)
        {
            vec[j + 1] = vec[j];
            --j;
            ++count;
        }
        vec[j + 1] = current;
    }

    return count;
}

int main()
{
    // FASTIO;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n;

        std::vector<int> v;
        for (int i = 0; i < 20; ++i)
        {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);
        }

        std::cout << n << " " << solve(v) << "\n";
    }

    int nn;
    std::cin >> nn;
    return 0;
}