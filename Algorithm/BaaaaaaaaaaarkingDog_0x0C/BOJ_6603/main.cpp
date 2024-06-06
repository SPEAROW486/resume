
#include <bits/stdc++.h>

constexpr int MAX = 13;

int k;
int sequence[MAX];
int arr[MAX];
bool isused[MAX];

void func(int c, int start)
{
    if (c == 6)
    {
        for (int i = 0; i < 6; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = start; i < k; ++i)
    {
        if (isused[i])
        {
            continue;
        }

        isused[i] = true;
        arr[c] = sequence[i];
        func(c + 1, i);
        isused[i] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (true)
    {

        std::cin >> k;

        if (k == 0)
        {
            break;
        }

        for (int i = 0; i < k; ++i)
        {
            std::cin >> sequence[i];
        }

        std::sort(sequence, sequence + k);
        func(0, 0);
        std::cout << "\n";
    }

    return 0;
}