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

    // 분배법칙을 활용
    // 이미 더해진 케이스가 있어서 그냥 팝 할떄가 있는데 이때 스택의 탑으로 검사를 하면 스택이 비어있을 떄가 있으므로
    // prev 커서를 활용
    // 한 스텝 한 스텝 씩 계산결과를 보면서 해야 될 듯..

    // 2 * (2+3*3)
    // 2*2 + 2*3*3
    // 더 한 값으로 보지말고 저 수식 자체를 한개의 쌍으로 보는게 이해가 편할듯

    int temp = 1;
    int answer = 0;
    char prev = '\0';
    for (const char &elem : str)
    {
        if (elem == '(' || elem == '[')
        {
            s.push(elem);
            if (elem == '(')
            {
                temp *= 2;
            }
            else
            {
                temp *= 3;
            }
        }
        else
        {
            if (elem == ')')
            {
                // 쌍을 만들지 못한다면
                if (s.empty())
                {
                    answer = 0;
                    break;
                }

                if (s.top() == '[')
                {
                    answer = 0;
                    break;
                }

                s.pop();
                if (prev == '(')
                {
                    answer += temp;
                }
                temp /= 2;
            }
            else if (elem == ']')
            {
                if (s.empty())
                {
                    answer = 0;
                    break;
                }

                if (s.top() == '(')
                {
                    answer = 0;
                    break;
                }

                s.pop();
                if (prev == '[')
                {
                    answer += temp;
                }
                temp /= 3;
            }
        }
        prev = elem;
    }

    if (!s.empty())
    {
        answer = 0;
    }
    std::cout << answer;
    return 0;
}
