
#include <bits/stdc++.h>

int n;
constexpr int MAX = 12;
int buf[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    // n의 최소값이 4인가?
    buf[1] = 1;
    buf[2] = 2;
    buf[3] = 4;

    for (int i = 4; i < 11; ++i)
    {
        buf[i] = buf[i - 3] + buf[i - 2] + buf[i - 1];
    }
    while (tc--)
    {
        std::cin >> n;
        std::cout << buf[n] << "\n";
    }

    // int nn;
    // std::cin >> n;
    return 0;
}