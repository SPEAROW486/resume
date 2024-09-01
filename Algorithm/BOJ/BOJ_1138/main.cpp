#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1138
// 그리디..

int n;
std::vector<int> heights;
std::vector<int> result;

int main()
{
    FASTIO;
    std::cin >> n;

    heights.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> heights[i];
    }

    result.resize(n);

    for (int i = 0; i < n; ++i)
    {
        int count = heights[i];
        for (int j = 0; j < n; ++j)
        {
            if (result[j] == 0)
            {
                if (count == 0)
                {
                    result[j] = i + 1;
                    break;
                }
                --count;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << result[i] << " ";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
