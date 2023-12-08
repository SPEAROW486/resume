#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;

        std::stack<char> s;
        for (const char &c : str)
        {
            if (s.empty())
            {
                s.push(c);
            }
            else
            {
                if (s.top() == c)
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }
        }

        if (s.empty())
        {
            ++count;
        }
    }

    std::cout << count;

    return 0;
}
