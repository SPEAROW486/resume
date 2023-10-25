#include <iostream>
#include <stack>

int main()
{
    int n = 0;
    std::cin >> n;

    std::stack<int> towers;
    for (int i = 0; i < n; ++i)
    {
        int top = 0;
        std::cin >> top;

        while (!towers.empty())
        {
        }

        if (towers.empty())
        {
            std::cout << 0 << " ";
        }
    }

    return 0;
}
