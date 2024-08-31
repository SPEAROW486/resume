#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    std::string input;
    getline(std::cin, input);

    std::stack<char> word;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '<')
        {
            while (!word.empty())
            {
                std::cout << word.top();
                word.pop();
            }
            while (i < input.size() && input[i] != '>')
            {
                std::cout << input[i];
                i++;
            }
            std::cout << input[i];
        }
        else if (input[i] == ' ')
        {
            while (!word.empty())
            {
                std::cout << word.top();
                word.pop();
            }
            std::cout << ' ';
        }
        else
        {
            word.push(input[i]);
        }
    }

    while (!word.empty())
    {
        std::cout << word.top();
        word.pop();
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
