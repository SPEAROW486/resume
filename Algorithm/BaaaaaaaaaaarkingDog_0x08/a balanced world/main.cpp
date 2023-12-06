#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    while (true)
    {
        std::string str;
        std::getline(std::cin, str);
        if (str == ".")
        {
            break;
        }

        std::stack<char> s;
        for (char c : str)
        {
            // 문자열 순회 다 하고 나서 스택이 비어있으면 yes고 아니면 no일듯
            if (c == '(' || c == '[')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }
            else if (c == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }
        }

        std::string answer = s.empty() ? "yes\n" : "no\n";
        std::cout << answer;
    }

    return 0;
}
