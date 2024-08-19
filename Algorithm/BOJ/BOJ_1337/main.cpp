
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
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    int min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        int cur = v[i];
        int cnt = 4;
        for (int j = i + 1; j < n; ++j)
        {
            if (v[j] == cur + 1 || v[j] == cur + 2 || v[j] == cur + 3 || v[j] == cur + 4)
            {
                --cnt;
            }
        }

        min = std::min(min, cnt);
    }
    std::cout << min << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}