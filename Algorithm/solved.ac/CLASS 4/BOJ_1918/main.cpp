
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int get_priorty(const char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}

std::string convert(const std::string &exp)
{
    std::string tmp;

    std::stack<char> s;

    for (int i = 0; i < exp.length(); ++i)
    {
        char a = exp[i];

        // 피연산자
        if (a >= 'A' && a <= 'Z')
        {
            tmp += a;
            continue;
        }

        // 괄호
        if (s.empty() || a == '(')
        {
            s.push(a);
            continue;
        }

        // 괄호
        if (a == ')')
        {
            while (s.top() != '(')
            {
                tmp += s.top();
                s.pop();
            }
            s.pop();
            continue;
        }

        // 연산자
        if (get_priorty(s.top()) < get_priorty(a))
        {
            s.push(a);
        }
        else
        {
            while (!s.empty() && get_priorty(s.top()) >= get_priorty(a))
            {
                tmp += s.top();
                s.pop();
            }
            s.push(a);
        }
    }

    while (!s.empty())
    {
        tmp += s.top();
        s.pop();
    }

    return tmp;
}

int main()
{
    FASTIO;
    std::string expression;
    std::cin >> expression;
    std::string ans = convert(expression);
    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}