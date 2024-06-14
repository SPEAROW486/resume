
#include <bits/stdc++.h>

constexpr int MAX = 1001;
int buf[MAX];
int n;
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

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