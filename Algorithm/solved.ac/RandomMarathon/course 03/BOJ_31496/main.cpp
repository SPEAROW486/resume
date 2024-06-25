
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

int n;
std::string s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> s;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        std::string item;
        int amount;

        std::cin >> item >> amount;

        if (item == s)
        {
            count += amount;
        }
        else
        {
            // Split item by '_'
            std::stringstream ss(item);
            std::string token;
            while (getline(ss, token, '_'))
            {
                if (token == s)
                {
                    count += amount;
                    break;
                }
            }
        }
    }

    std::cout << count;

    // int nn;
    // std::cin >> nn;

    return 0;
}