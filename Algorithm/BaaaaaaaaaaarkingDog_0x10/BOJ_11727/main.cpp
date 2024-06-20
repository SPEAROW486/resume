
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1001;
constexpr int MOD = 10007;
int d[MAX];
// N은 1000
// 시간제한은1초

// 테이블 : D[i] = N이 i일때 2*i크기의 직사각형을 채우는 방법의 수

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n;

    d[1] = 1;
    d[2] = 3;

    for (int i = 3; i <= n; ++i)
    {
        d[i] = d[i - 1] % MOD + d[i - 2] % MOD + d[i - 2] % MOD;
    }

    std::cout << d[n] % MOD;

    // int nn;
    // std::cin >> nn;
    return 0;
}