
#include <bits/stdc++.h>

constexpr int MAX = 300001;
int buf[MAX];
int n;

int GetTrimmed()
{
    double ret = std::round((double)n * 0.15);
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;

    if (n == 0)
    {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    std::sort(buf, buf + n);

    int trim = GetTrimmed();
    int sum = 0;
    for (int i = trim; i < n - trim; ++i)
    {
        sum += buf[i];
    }

    int avg = std::round((double)sum / (n - 2 * trim));

    std::cout << avg;

    // int nn;
    // std::cin >> nn;

    return 0;
}