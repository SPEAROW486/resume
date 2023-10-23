#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s;
    int n = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        std::cin >> temp;

        if (temp != 0)
        {
            s.push(temp);
        }
        else
        {
            s.pop();
        }
    }

    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    std::cout << sum;
    return 0;
}
