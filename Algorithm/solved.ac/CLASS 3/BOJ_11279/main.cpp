
#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::less<int>> p;
    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;

        if (number > 0)
        {
            p.push(number);
        }
        else
        {
            int ans = 0;
            if (!p.empty())
            {
                ans = p.top();
                p.pop();
            }
            std::cout << ans << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}