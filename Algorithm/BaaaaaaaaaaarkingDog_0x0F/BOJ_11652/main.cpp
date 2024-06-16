
#include <bits/stdc++.h>

constexpr int MAX = 100001;
long long buf[MAX];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    std::sort(buf, buf + n);

    int cnt = 0;
    int max_cnt = 0;
    long long max_number = -(1ll << 62) - 1;
    buf[n] = (1ll << 62) + 1;

    for (int i = 0; i <= n; ++i)
    {
        if (i == 0)
        {
            ++cnt;
        }
        else if (buf[i] == buf[i - 1])
        {
            ++cnt;
        }
        else
        {
            if (cnt > max_cnt)
            {
                max_number = std::max(buf[i - 1], max_number);
            }
            max_cnt = std::max(cnt, max_cnt);
            cnt = 1;
        }
    }
    std::cout << max_number;

    // int nn;
    // std::cin >> n;
    return 0;
}