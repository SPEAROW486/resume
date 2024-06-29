
#include <bits/stdc++.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        int m, n, x, y;
        std::cin >> m >> n >> x >> y;

        int result = -1;
        int dest = lcm(m, n);

        // x에 m을 계속 더하면 x값은 변하지 않는 상태이므로
        // 해당 해를 n으로 나누다가 y값이랑 같아지면 찾은것.
        for (int i = x; i <= dest; i += m)
        {
            int ny = i % n;
            if (ny == 0)
            {
                ny = n;
            }

            if (ny == y)
            {
                result = i;
                break;
            }
        }
        std::cout << result << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}