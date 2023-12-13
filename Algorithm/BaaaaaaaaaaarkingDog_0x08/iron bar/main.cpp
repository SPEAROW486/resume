#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    std::cin >> str;

    std::stack<char> s;
    int count = 0;
    char last;
    for (const char &elem : str)
    {
        if (elem != ')')
        {
            s.push(elem);
        }
        else
        {
            if (!s.empty())
            {
                s.pop();
            }

            if (last == '(')
            {
                count += s.size();
            }
            else
            {
                ++count;
            }
        }
        last = elem;
    }

    std::cout << count;

    return 0;
}
