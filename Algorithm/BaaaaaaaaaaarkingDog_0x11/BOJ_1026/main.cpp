
#include <bits/stdc++.h>

constexpr int MAX = 51;
int n;
int a[MAX];
int b[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> b[i];
    }
    std::sort(a, a + n);
    std::sort(b, b + n);

    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += a[i] * b[n - 1 - i];
    }

    std::cout << s;

    return 0;
}