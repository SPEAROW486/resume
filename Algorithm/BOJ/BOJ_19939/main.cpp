
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;

int main()
{
    // FASTIO;
    std::cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= k; ++i)
    {
        sum += i;
    }

    // 1부터 k까지의 합을 구해서
    // n에서 뺌

    n -= sum;
    if (n < 0)
    {
        std::cout << -1;
    }
    else
    {
        if (n % k == 0)
        {
            std::cout << k - 1;
        }
        else
        {
            std::cout << k;
        }
    }

    int nn;
    std::cin >> nn;
    return 0;
}