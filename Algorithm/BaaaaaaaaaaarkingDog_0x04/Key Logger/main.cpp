#include <iostream>
#include <string>
#include <list>

int main()
{
    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        std::list<char> password;
        auto cursor = password.end();

        for (const char elem : s)
        {
            if (elem == '<')
            {
                if (cursor != password.begin())
                {
                    --cursor;
                }
            }
            else if (elem == '>')
            {
                if (cursor != password.end())
                {
                    ++cursor;
                }
            }
            else if (elem == '-')
            {
                if (cursor != password.begin())
                {
                    cursor = password.erase(--cursor);
                }
            }
            else
            {
                cursor = password.insert(cursor, elem);
                ++cursor;
            }
        }

        for (const char c : password)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}