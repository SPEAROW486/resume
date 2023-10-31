#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    std::stack<std::pair<int, int>> s;
    int buf[1000000] = {0};

    buf[n - 1] = -1;
    for (int i = 0; i < n; ++i)
    {
        int input = 0;
        std::cin >> input;

        if (s.empty())
        {
            s.push(std::pair<int, int>(input, i));
            continue;
        }

        while (!s.empty())
        {
            if (s.top().first < input)
            {
                buf[s.top().second] = input;
                s.pop();
            }
            else
            {
                buf[s.top().second] = -1;
                break;
            }
        }

        s.push(std::pair<int, int>(input, i));
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << buf[i] << " ";
    }

    return 0;
}
