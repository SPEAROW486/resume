
#include <bits/stdc++.h>

int n;
constexpr int MAX = 10001;

int buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;
        ++buf[number];
    }

    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < buf[i]; ++j)
        {
            std::cout << i << "\n";
        }
    }

    return 0;
}