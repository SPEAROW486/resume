#include <bits/stdc++.h>

int n;
std::priority_queue<int> sp;
std::priority_queue<int, std::vector<int>, std::greater<int>> sm;

int main()
{
    std::cin >> n;
    bool exist_zero = false;
    for (int i = 0; i < n; ++i)
    {
        int number = 0;
        std::cin >> number;

        if (number == 0)
        {
            exist_zero = true;
            continue;
        }

        if (number > 0)
        {
            sp.push(number);
        }
        else
        {
            sm.push(number);
        }
    }

    int total = 0;
    while (sp.size() > 1)
    {
        int num1 = sp.top();
        sp.pop();

        int num2 = sp.top();
        sp.pop();

        if (num1 == 1 || num2 == 1)
        {
            total += num1 + num2;
        }
        else
        {
            total += num1 * num2;
        }
    }

    if (!sp.empty())
    {
        total += sp.top();
        sp.pop();
    }

    while (sm.size() > 1)
    {
        int num1 = sm.top();
        sm.pop();

        int num2 = sm.top();
        sm.pop();

        total += num1 * num2;
    }

    if (!sm.empty())
    {
        if (!exist_zero)
        {
            total += sm.top();
            sm.pop();
        }
    }

    std::cout << total;

    // int nn;
    // std::cin >> nn;

    return 0;
}
