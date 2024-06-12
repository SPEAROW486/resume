
#include <bits/stdc++.h>

int n, m;
constexpr int MAX = 1000001;
int buf[MAX];

int main()
{
    std::cin >> m >> n;

    for (int i = 2; i <= n; ++i)
    {
        buf[i] = i;
    }

    for (int i = 2; i <= n; ++i)
    {
        int multi = 2;
        while (true)
        {
            int sqr = i * multi;
            if (sqr > n)
            {
                break;
            }

            buf[sqr] = 0;
            ++multi;
        }
    }

    for (int i = m; i <= n; ++i)
    {
        if (buf[i] != 0)
        {
            std::cout << buf[i] << "\n";
        }
    }

    return 0;
}