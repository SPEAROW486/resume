
#include <bits/stdc++.h>

int main()
{

    int n;
    std::cin >> n;

    int cnt = 0;
    int number = 0;
    while (true)
    {
        std::string s = std::to_string(number);
        if (s.find("666") != std::string::npos)
        {
            ++cnt;
            if (cnt == n)
            {
                break;
            }
        }
        ++number;
    }
    std::cout << number;

    return 0;
}