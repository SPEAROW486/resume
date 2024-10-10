#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

using namespace std;

int main()
{
    FASTIO;

    // BOJ : 9094

    int T;
    std::cin >> T;

    while (T--)
    {
        int n, m, count = 0;
        std::cin >> n >> m;

        // 두 수의 합이 n의 배수인 경우를 찾아봅니다.
        for (int a = 1; a < n - 1; ++a)
        {
            for (int b = a + 1; b < n; ++b)
            {
                if ((a * a + b * b + m) % (a * b) == 0)
                {
                    ++count;
                }
            }
        }

        std::cout << count << '\n';
    }

    return 0;
}
