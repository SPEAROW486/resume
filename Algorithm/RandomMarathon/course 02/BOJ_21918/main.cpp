
#include <bits/stdc++.h>

int n, m;
constexpr int MAX = 4001;
int buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1)
        {
            buf[b - 1] = c;
        }
        else if (a == 2)
        {
            for (int j = b - 1; j < c; ++j)
            {
                buf[j] = !buf[j];
            }
        }
        else if (a == 3)
        {
            for (int j = b - 1; j < c; ++j)
            {
                buf[j] = 0;
            }
        }
        else
        {
            for (int j = b - 1; j < c; ++j)
            {
                buf[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << buf[i] << " ";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}