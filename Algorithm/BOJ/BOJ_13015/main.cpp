
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    // FASTIO;

    std::cin >> n;

    int a = 0;
    int b = n - 1;
    int c = 3 * n - 3;
    int d = 4 * n - 4;

    for (int i = 1; i < 2 * n; ++i)
    {
        if (i == 1 || i == 2 * n - 1)
        {
            for (int j = a; j <= b; ++j)
            {
                std::cout << "*";
            }

            for (int j = b + 1; j < c; ++j)
            {
                std::cout << " ";
            }

            for (int j = c; j <= d; ++j)
            {
                std::cout << "*";
            }
        }
        else
        {
            for (int j = 0; j < a; j++)
            {
                std::cout << " ";
            }
            std::cout << "*";
            for (int j = a + 1; j < b; j++)
            {
                std::cout << " ";
            }
            std::cout << "*";
            for (int j = b + 1; j < c; j++)
            {
                std::cout << " ";
            }
            if (b != c)
            {
                std::cout << "*";
            }
            for (int j = c + 1; j < d; j++)
            {
                std::cout << " ";
            }
            std::cout << "*";
        }
        std::cout << "\n";

        if (i < n)
        {
            a++;
            b++;
            c--;
            d--;
        }
        else
        {
            a--;
            b--;
            c++;
            d++;
        }
    }

    int nn;
    std::cin >> nn;
    return 0;
}