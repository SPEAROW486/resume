
#include <bits/stdc++.h>

std::queue<int> q;

int main()
{
    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        q.push(i + 1);
    }

    std::vector<int> josephus;
    while (!q.empty())
    {
        for (int i = 0; i < k; ++i)
        {
            int front = q.front();
            q.pop();

            if (i == k - 1)
            {
                josephus.push_back(front);
            }
            else
            {
                q.push(front);
            }
        }
    }

    std::cout << "<";
    for (int i = 0; i < josephus.size(); ++i)
    {
        std::cout << josephus[i];
        std::string delimiter = i == josephus.size() - 1 ? "" : ", ";
        std::cout << delimiter;
    }
    std::cout << ">";

    return 0;
}