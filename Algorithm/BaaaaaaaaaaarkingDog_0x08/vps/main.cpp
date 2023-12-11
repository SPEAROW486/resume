#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t = 0;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        std::string str;
        std::cin >> str;

        std::stack<char> s;
        for (const char &elem : str)
        {
            if (elem != ')')
            {
                s.push(elem);
            }
            else
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(elem);
                }
            }
        }

        std::string msg = s.empty() ? "YES" : "NO";
        std::cout << msg << std::endl;
    }

    return 0;
}
