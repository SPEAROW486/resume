
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 10001;
std::vector<int> constructors(MAX);

int sum_of_digits(int i)
{
    int tmp = 0;

    while (i > 0)
    {
        tmp += i % 10;
        i /= 10;
    }
    return tmp;
}

int main()
{
    FASTIO;

    for (int i = 1; i < MAX; ++i)
    {
        int idx = i + sum_of_digits(i);
        if (idx < MAX)
        {
            ++constructors[idx];
        }
    }

    for (int i = 1; i < MAX; ++i)
    {
        if (constructors[i] == 0)
        {
            std::cout << i << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}