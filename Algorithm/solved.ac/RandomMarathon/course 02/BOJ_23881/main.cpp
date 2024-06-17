
#include <bits/stdc++.h>

int n, k;
constexpr int MAX = 10001;
int buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    int a, b;
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int last = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (buf[j] <= buf[last])
            {
                continue;
            }

            last = j;
        }

        if (last != i)
        {
            ++cnt;
            std::swap(buf[last], buf[i]);

            if (cnt == k)
            {
                a = buf[last];
                b = buf[i];
            }
        }
    }

    if (cnt < k)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << a << " " << b << "\n";
    }

    return 0;
}