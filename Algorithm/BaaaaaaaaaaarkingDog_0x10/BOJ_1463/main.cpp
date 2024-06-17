
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1000001;
int buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    int cnt = 0;

    buf[1] = 0;
    buf[2] = 1;
    buf[3] = 1;

    for (int i = 4; i <= n; ++i)
    {
        buf[i] = buf[i - 1] + 1;
        if (i % 3 == 0)
        {
            buf[i] = std::min(buf[i], buf[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            buf[i] = std::min(buf[i], buf[i / 2] + 1);
        }
    }

    std::cout << buf[n];

    // int nn;
    // std::cin >> n;
    return 0;
}