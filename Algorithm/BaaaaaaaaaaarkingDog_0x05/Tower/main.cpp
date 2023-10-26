#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n = 0;
    std::cin >> n;

    std::stack<std::pair<int, int>> towers;
    for (int i = 0; i < n; ++i)
    {
        int top = 0;
        std::cin >> top;

        while (!towers.empty())
        {
            if (towers.top().first > top)
            {
                std::cout << towers.top().second << " ";
                break;
            }
            towers.pop();
        }

        if (towers.empty())
        {
            std::cout << 0 << " ";
        }
        towers.push(std::pair<int, int>(top, i + 1));
    }

    return 0;
}
