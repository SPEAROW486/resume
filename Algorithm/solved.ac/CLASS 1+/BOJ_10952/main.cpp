#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    while (true)
    {
        int a, b;
        std::cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }

        std::cout << a + b << "\n";
    }

    return 0;
}