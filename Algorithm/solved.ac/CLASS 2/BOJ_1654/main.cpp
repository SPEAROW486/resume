
#include <bits/stdc++.h>

int k, n;
constexpr int MAX = 10000;
unsigned int buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> k >> n;
    for (int i = 0; i < k; ++i)
    {
        std::cin >> buf[i];
    }

    unsigned int min = 1;
    unsigned int max = *std::max_element(buf, buf + k);
    while (min <= max)
    {
        unsigned int mid = (min + max) / 2;
        unsigned int cnt = 0;
        for (int i = 0; i < k; ++i)
        {
            cnt += buf[i] / mid;
        }

        if (cnt >= n)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    std::cout << max;

    return 0;
}