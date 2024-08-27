
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    int n;

    // 직접 배수를 구하면서 1로 이루어져있는지 검사하니까 시간이 초과됨
    // 반대로 1, 11, 111을 만들면서 n으로 나누어 떨어지는지를 확인하면 되는데
    // 숫자가 엄청 커질 수 있으니 나머지 연산을 활용함.
    while (std::cin >> n)
    {
        int num = 1;
        int length = 1;

        while (num % n != 0)
        {
            num = (num * 10 + 1) % n;
            ++length;
        }

        std::cout << length << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}