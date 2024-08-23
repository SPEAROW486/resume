
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

std::stack<int> s;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd == 1)
        {
            int tmp;
            std::cin >> tmp;
            s.push(tmp);
        }
        else if (cmd == 2)
        {
            if (s.size() > 0)
            {
                std::cout << s.top() << "\n";
                s.pop();
            }
            else
            {
                std::cout << "-1\n";
            }
        }
        else if (cmd == 3)
        {
            std::cout << s.size() << "\n";
        }
        else if (cmd == 4)
        {
            if (s.empty())
            {
                std::cout << "1\n";
            }
            else
            {
                std::cout << "0\n";
            }
        }
        else if (cmd == 5)
        {
            if (s.size() > 0)
            {
                std::cout << s.top() << "\n";
            }
            else
            {
                std::cout << "-1\n";
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}