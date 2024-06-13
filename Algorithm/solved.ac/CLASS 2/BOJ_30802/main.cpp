
#include <bits/stdc++.h>

int n;
constexpr int MAX = 6;

int buf[MAX];

int main()
{

    int n;
    std::cin >> n;

    for (int i = 0; i < MAX; ++i)
    {
        std::cin >> buf[i];
    }

    int t, p;
    std::cin >> t >> p;

    int cnt = 0;
    for (int i = 0; i < MAX; ++i)
    {
        // 해당 사이즈를 아무도 신청하지 않을 수 있는 반례가 존재했음.
        // 이렇게 반례는 뭔가 이상한 값을 생각해봐야 할듯.
        if (buf[i] == 0)
        {
            continue;
        }

        if (buf[i] / t == 0)
        {
            ++cnt;
        }
        else
        {
            cnt += buf[i] / t;

            int moduler = buf[i] % t != 0 ? 1 : 0;
            cnt += moduler;
        }
    }

    std::cout << cnt << "\n";
    std::cout << n / p << " " << n % p;

    int nn;
    std::cin >> nn;

    return 0;
}