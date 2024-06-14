
#include <bits/stdc++.h>

int buf[42];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::fill(buf, buf + 42, -1);
    for (int i = 0; i < 10; ++i)
    {
        int n;
        std::cin >> n;
        ++buf[n % 42];
    }

    int cnt = 0;
    for (int i = 0; i < 42; ++i)
    {
        if (buf[i] != -1)
        {
            ++cnt;
        }
    }

    std::cout << cnt;

    return 0;
}