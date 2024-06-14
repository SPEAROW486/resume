
#include <bits/stdc++.h>

constexpr int MAX = 8;
int buf[MAX];

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    for (int i = 0; i < MAX; ++i)
    {
        std::cin >> buf[i];
    }

    bool is_ascending = true;
    for (int i = 1; i < MAX; ++i)
    {
        is_ascending &= buf[i] == buf[i - 1] + 1;
    }

    if (is_ascending)
    {
        std::cout << "ascending\n";
        return 0;
    }

    bool is_descending = true;
    for (int i = 1; i < MAX; ++i)
    {
        is_descending &= buf[i] + 1 == buf[i - 1];
    }

    if (is_descending)
    {
        std::cout << "descending\n";
        return 0;
    }

    std::cout << "mixed\n";

    return 0;
}