
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

long long n;
constexpr long long MOD = 1000000007;
std::map<long long, long long> map;

long long fibo(long long x)
{
    if (map.count(x) > 0)
    {
        return map[x];
    }

    long long result = 0;
    if (x % 2 == 0)
    {
        // 짝수
        result = (fibo(x / 2) * (fibo(x / 2 + 1) + fibo(x / 2 - 1))) % MOD;
    }
    else
    {
        // 홀수
        result = ((fibo((x + 1) / 2) * fibo((x + 1) / 2)) % MOD + (fibo((x - 1) / 2) * fibo((x - 1) / 2)) % MOD) % MOD;
    }
    return map[x] = result % MOD;
}

int main()
{
    // FASTIO;
    std::cin >> n;

    // 피보나치 기본 점화식을 쭉 전개하면 새로운 점화식이 나옴
    // 그걸 이용해서 DP + 재귀로 분할정복
    map[0] = 0;
    map[1] = 1;
    map[2] = 1;

    std::cout << fibo(n);

    int nn;
    std::cin >> nn;

    return 0;
}