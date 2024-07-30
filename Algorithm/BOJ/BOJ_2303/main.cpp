
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::vector<int>> v;

int solve(const std::vector<int> &vec)
{
    std::vector<bool> select = {false, false, false, true, true};

    int result = 0;
    do
    {
        int sum = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (!select[i])
            {
                sum += vec[i];
            }
        }
        result = std::max(result, sum % 10);
    } while (std::next_permutation(select.begin(), select.end()));

    return result;
}

int main()
{
    FASTIO;
    std::cin >> n;

    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int num;
            std::cin >> num;
            v[i].push_back(num);
        }
    }

    int max = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
        int ret = solve(v[i]);

        if (ret >= max)
        {
            max = ret;
            idx = i + 1;
        }
    }

    std::cout << idx;

    int nn;
    std::cin >> nn;
    return 0;
}