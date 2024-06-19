
#include <bits/stdc++.h>

int n, m;
constexpr int MAX = 100001;
int d[MAX];
int a[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // i = 2, j = 3이라고 할때
    // D[i] = 1부터 i까지의 수를 더 한것
    // R[j] = D[j] - D[i-1];

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
    }

    d[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        d[i] = d[i - 1] + a[i];
    }

    while (m--)
    {
        int left, right;
        std::cin >> left >> right;
        std::cout << d[right] - d[left - 1] << "\n";
    }
    // int nn;
    // std::cin >> n;
    return 0;
}