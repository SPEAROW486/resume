
#include <bits/stdc++.h>

constexpr int MAX = 1000001;
int buf[MAX];
int n;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    std::sort(buf, buf + n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << buf[i] << "\n";
    }

    return 0;
}