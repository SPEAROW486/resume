
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<int> vec;

int main()
{
    FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;

        int left = 0;
        int right = vec.size() - 1;

        int idx = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (tmp == vec[mid])
            {
                idx = mid;
            }

            if (tmp > vec[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        std::cout << idx << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}