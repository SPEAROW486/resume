
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;

int get_max_prime_factor(int n)
{
    int result = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            if (result < i)
            {
                result = i;
            }
            n /= i;
        }
    }

    if (n > 1)
    {
        if (result < n)
        {
            result = n;
        }
    }
    return result == 0 ? n : result;
}

int main()
{
    FASTIO;
    std::cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        // i의 소인수를 구한다음
        // 그 소인수들이 k보다 작으면 ++
        int max = get_max_prime_factor(i);
        if (max <= k)
        {
            ++ans;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}