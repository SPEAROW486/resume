
#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int l;
    std::cin >> l;

    std::string s;
    std::cin >> s;

    int r = 31;
    int m = 1234567891;

    unsigned long long ri = 1;
    unsigned long long sum = 0;
    for (int i = 0; i < l; ++i)
    {
        int ai = s[i] - 96;
        if (i != 0)
        {
            // ri를 계속 제곱하다보면 오버플로우가 발생함.
            // 그래서 50점이였는데
            // 단순히 long long으로 범위를 늘려줘도 해결이 안될정도로 값이 커지기 때문에
            // 나머지 법칙을 사용
            ri *= r;
            ri %= m;
        }
        unsigned long long result = ai * ri;
        sum = (sum + result) % m;
    }

    std::cout << sum;

    return 0;
}