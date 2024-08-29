
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

int solve()
{
    std::stack<int> stack;
    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
        {
            stack.push(s[i] - '0'); // 문자를 정수로 변환하여 push
        }
        else
        {
            int rhs = stack.top();
            stack.pop();
            int lhs = stack.top();
            stack.pop();

            int tmp = 0;
            if (s[i] == '+')
            {
                tmp = lhs + rhs;
            }
            else if (s[i] == '-')
            {
                tmp = lhs - rhs;
            }
            else if (s[i] == '*')
            {
                tmp = lhs * rhs;
            }
            else if (s[i] == '/')
            {
                tmp = lhs / rhs;
            }

            stack.push(tmp);
        }
    }

    int result = stack.top();
    return result;
}
int main()
{
    // FASTIO;
    std::cin >> s;
    std::cout << solve();

    int nn;
    std::cin >> nn;
    return 0;
}