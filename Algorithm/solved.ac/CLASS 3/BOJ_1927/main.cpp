
#include <bits/stdc++.h>

int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> p;

    for (int i = 0; i < n; ++i)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd == 0)
        {
            if (p.size() > 0)
            {
                std::cout << p.top() << "\n";
                p.pop();
            }
            else
            {
                std::cout << 0 << "\n";
            }
        }
        else
        {
            p.push(cmd);
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}