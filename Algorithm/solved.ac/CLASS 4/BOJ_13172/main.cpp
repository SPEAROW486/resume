
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MOD = 1'000'000'007;
int m;

// MOD = 1000000007니까 1000000005를 구해야한대
// 저 2개의 결과가 같으니까
// 그럼 100000005를 분할정복으로
long long comupte_reverse(long long b, long long exp)
{
    if (exp == 1)
    {
        return b;
    }

    if (exp % 2 == 1)
    {
        // 홀수 지수
        return b * comupte_reverse(b, exp - 1) % MOD;
    }
    // 짝수면
    long long sqrt = comupte_reverse(b, exp / 2);

    return sqrt * sqrt % MOD;
}

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    FASTIO;
    std::cin >> m;

    long long ans = 0;
    for (int i = 0; i < m; ++i)
    {
        long long b, a;
        std::cin >> b >> a;

        long long g = gcd(a, b);
        a /= g; // si
        b /= g; // ni

        ans += a * comupte_reverse(b, MOD - 2) % MOD;
        ans %= MOD;
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}