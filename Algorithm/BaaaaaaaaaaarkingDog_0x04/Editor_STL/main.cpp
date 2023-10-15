#include <iostream>
#include <string>
#include <list>

int main()
{
    std::string s;

    std::cin >> s;

    std::list<char> list(s.begin(), s.end());

    int n = 0;
    std::cin >> n;

    auto cursor = list.end();
    for (int i = 0; i < n; ++i)
    {
        char command;
        std::cin >> command;

        if (command == 'L' && cursor != list.begin())
        {
            // <<
            --cursor;
        }
        else if (command == 'D' && cursor != list.end())
        {
            // >>
            ++cursor;
        }
        else if (command == 'B' && cursor != list.begin())
        {
            cursor = list.erase(--cursor);
        }
        else if (command == 'P')
        {
            char str;
            std::cin >> str;
            list.insert(cursor, str);
        }
    }

    for (const char &elem : list)
    {
        std::cout << elem;
    }
    std::cout << std::endl;

    return 0;
}
