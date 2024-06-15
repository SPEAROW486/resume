
#include <bits/stdc++.h>

constexpr int MAX = 1000001;
int a[MAX];
int b[MAX];
int c[MAX * 2];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::fill(a, a + MAX, std::numeric_limits<int>::max());
    std::fill(b, b + MAX, std::numeric_limits<int>::max());

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }

    int aidx = 0;
    int bidx = 0;
    for (int i = 0; i < n + m; ++i)
    {
        c[i] = a[aidx] < b[bidx] ? a[aidx++] : b[bidx++];
    }

    for (int i = 0; i < n + m; ++i)
    {
        std::cout << c[i] << " ";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}