
#include <bits/stdc++.h>

int n;
std::set<int> s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string cmd;
        int number;

        std::cin >> cmd;

        if (cmd == "add")
        {
            std::cin >> number;
            s.insert(number);
        }
        else if (cmd == "remove")
        {
            std::cin >> number;
            s.erase(number);
        }
        else if (cmd == "check")
        {
            std::cin >> number;
            int result = s.find(number) != s.end() ? 1 : 0;
            std::cout << result << "\n";
        }
        else if (cmd == "toggle")
        {
            std::cin >> number;
            if (s.find(number) != s.end())
            {
                s.erase(number);
            }
            else
            {
                s.insert(number);
            }
        }
        else if (cmd == "all")
        {
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        }
        else if (cmd == "empty")
        {
            s.clear();
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}