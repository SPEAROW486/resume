
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 11;
int n, m, apple;

int main()
{
    FASTIO;
    std::cin >> n >> m >> apple;

    int start = 1;
    int end = m;
    int cnt = 0;

    for (int i = 0; i < apple; ++i)
    {
        int tmp;
        std::cin >> tmp;

        while (true)
        {
            if (start <= tmp && tmp <= end)
            {
                break;
            }
            else if (start > tmp)
            {
                --start;
                --end;
                ++cnt;
            }
            else
            {
                ++start;
                ++end;
                ++cnt;
            }
        }
    }

    std::cout << cnt;

    // int nn;
    // std::cin >> nn;
    return 0;
}