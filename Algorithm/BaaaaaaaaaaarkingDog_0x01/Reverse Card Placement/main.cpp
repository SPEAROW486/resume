#include <iostream>
#include <algorithm>

int main()
{
    constexpr int card_count = 20;
    int card[card_count] = {0};

    for (int i = 0; i < card_count; ++i)
    {
        card[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        for (int swap_count = (b - a + 1) / 2; swap_count > 0; --swap_count)
        {
            std::swap(card[a - 1], card[b - 1]);
            ++a;
            --b;
        }
    }

    for (int i = 0; i < card_count; ++i)
    {
        std::cout << card[i] << " ";
    }

    return 0;
}