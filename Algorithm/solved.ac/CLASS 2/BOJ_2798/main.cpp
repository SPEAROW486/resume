
#include <bits/stdc++.h>

constexpr int MAX = 101;
int buf[MAX];
int n, m;

int main()
{
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    int max_number = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int temp = buf[i] + buf[j] + buf[k];
                if (temp <= m)
                {
                    max_number = std::max(max_number, temp);
                }
            }
        }
    }

    std::cout << max_number;

    return 0;
}