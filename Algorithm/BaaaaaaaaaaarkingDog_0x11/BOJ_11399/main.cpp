
#include <bits/stdc++.h>

int n;
constexpr int MAX = 1001;
int p[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
    }
    std::sort(p, p + n);

    int time = p[0];
    for (int i = 1; i < n; ++i)
    {
        int wait = p[i];
        for (int j = i - 1; j >= 0; --j)
        {
            wait += p[j];
        }
        time += wait;
    }

    std::cout << time;

    // int nn;
    // std::cin >> nn;
    return 0;
}