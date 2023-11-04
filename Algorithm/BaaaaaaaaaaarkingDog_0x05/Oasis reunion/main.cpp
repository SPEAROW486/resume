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

    long long count = 0;
    for (int i = 0; i < n; ++i)
    {
        int input = 0;
        std::cin >> input;

        if (s.empty())
        {
            s.push(std::pair<int, int>(input, 1));
            continue;
        }

        while (!s.empty() && s.top().first < input)
        {
            s.pop();
            count++;
        }

        if (!s.empty())
        {
            if (s.top().first == input)
            {
                count += s.top().second;
                s.push(std::pair<int, int>(input, s.top().second + 1));
            }
            else if (s.top().first > input)
            {
                // 자기 자신 + 큰거 하나 까지 볼 수 있으니까 2
                count++;
                s.push(std::pair<int, int>(input, 2));
            }
        }
        else
        {
            s.push(std::pair<int, int>(input, 1));
        }
    }

    std::cout << count;

    return 0;
}
