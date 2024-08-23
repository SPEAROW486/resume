
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<int> v;

bool check(int h)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == 0)
        {
            if (v[i] - h > 0)
            {
                return false;
            }
        }

        if (v[i] + h < v[i + 1] - h)
        {
            return false;
        }

        if (i == v.size() - 1)
        {
            if (v[i] + h < n)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // FASTIO;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    int left = 0;
    int right = n;
    int ans = INT_MAX;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans;

    int nn;
    std::cin >> nn;
    return 0;
}