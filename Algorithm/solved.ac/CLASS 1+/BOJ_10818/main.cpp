
#include <bits/stdc++.h>

constexpr int MAX = 1000001;
int buf[1000001];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> buf[i];
    }

    std::cout << *std::min_element(buf, buf + n) << " " << *std::max_element(buf, buf + n);
    return 0;
}