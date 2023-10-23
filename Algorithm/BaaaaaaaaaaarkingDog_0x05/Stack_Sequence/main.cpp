#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::stack<int> s;
    int n = 0;

    std::cin >> n;

    int sequence[100001] = {0};
    for (int i = 0; i < n; ++i)
    {
        std::cin >> sequence[i];
    }

    int counter = 0;
    std::vector<std::string> ans;
    for (int k = 1; k <= n; ++k)
    {
        s.push(k);
        ans.push_back("+");

        while (!s.empty() && s.top() == sequence[counter])
        {
            ++counter;
            s.pop();
            ans.push_back("-");
        }
    }

    if (s.empty())
    {
        for (const auto &elem : ans)
        {
            std::cout << elem << "\n";
        }
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}
