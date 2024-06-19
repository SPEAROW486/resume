
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1000001;
int d[MAX];
int path[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // d[i] = i를 1로 만드는 연산의 최소 횟수라고 했을 때
    std::cin >> n;

    // 1,2,3을 각 1로 만드는데 필요한 연산의 최소 횟수
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;

    path[1] = 0;
    path[2] = 1;
    path[3] = 1;
    // 최적의 경로를 저장해놓아야 하는데
    // 최적의 경로라는건 연산을 제일 적게 사용하는 경로...

    for (int i = 4; i <= n; ++i)
    {
        d[i] = d[i - 1] + 1;
        path[i] = i - 1;
        if (i % 3 == 0 && d[i] > d[i / 3] + 1)
        {
            d[i] = d[i / 3] + 1;
            path[i] = i / 3;
        }

        if (i % 2 == 0 && d[i] > d[i / 2] + 1)
        {
            d[i] = d[i / 2] + 1;
            path[i] = i / 2;
        }
    }

    std::cout << d[n] << "\n";
    while (n != 0)
    {
        std::cout << n << " ";
        n = path[n];
    }

    // int nn;
    // std::cin >> n;
    return 0;
}