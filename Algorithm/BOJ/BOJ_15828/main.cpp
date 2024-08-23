
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::queue<int> q;

int main()
{
    FASTIO;

    std::cin >> n;
    while (true)
    {
        int tmp;
        std::cin >> tmp;

        if (tmp == -1)
        {
            if (!q.empty())
            {
                while (!q.empty())
                {
                    std::cout << q.front() << " ";
                    q.pop();
                }
            }
            else
            {
                std::cout << "empty\n";
            }
            break;
        }

        if (n > q.size())
        {
            if (tmp > 0)
            {
                q.push(tmp);
            }
        }

        if (tmp == 0)
        {
            q.pop();
        }
    }
    // int nn;
    // std::cin >> nn;

    return 0;
}