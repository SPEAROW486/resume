
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

using ll = long long;

ll n;
constexpr int MAX = 21;
// n으 범위가 19!보다 크고 20!보다 작으므로
std::vector<long long> facto(MAX);

int main()
{
    FASTIO;
    std::cin >> n;

    facto[0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        facto[i] = i * facto[i - 1];
    }

    bool possible = false;
    if (n == 0)
    {
        possible = false;
    }
    else
    {
        // 임의의 숫자 x가 있을때
        // x가 3 이상이라면
        // x! > x 가 항상 성립함.
        for (int i = 20; i >= 0; --i)
        {
            if (facto[i] <= n)
            {
                n -= facto[i];
            }
        }

        possible = n == 0;
    }

    std::string ans = possible ? "YES\n" : "NO\n";
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}