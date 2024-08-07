
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    // FASTIO;

    int n;
    std::cin >> n;

    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    int left = 0;
    int right = v[n - 1];
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int tmp = n - (std::lower_bound(v.begin(), v.end(), mid) - v.begin());

        if (tmp < mid)
        {
            right = mid - 1;
        }
        else
        {
            ans = mid;
            left = mid + 1;
        }
    }

    std::cout << ans;

    int nn;
    std::cin >> nn;
    return 0;
}