
#include <bits/stdc++.h>

int n;
constexpr int MAX = 5001;

int buf[MAX];

int main()
{

    int n;
    std::cin >> n;

    std::fill(buf, buf + MAX, 0);
    buf[3] = 1;
    buf[5] = 1;

    // 0 1 2 4는 고려할 필요가없음.
    for (int i = 3; i < n; ++i)
    {
        if (buf[i] == 0)
        {
            continue;
        }
        buf[i + 3] = buf[i + 3] != 0 ? std::min(buf[i + 3], buf[i] + 1) : buf[i] + 1;
        buf[i + 5] = buf[i + 5] != 0 ? std::min(buf[i + 5], buf[i] + 1) : buf[i] + 1;
    }

    int result = buf[n] != 0 ? buf[n] : -1;
    std::cout << result;

    return 0;
}