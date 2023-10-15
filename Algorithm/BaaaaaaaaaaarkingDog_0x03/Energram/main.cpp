#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string a;
    std::string b;

    std::cin >> a >> b;

    int count = 0;

    std::string temp = b;
    for (size_t i = 0; i < a.length(); ++i)
    {
        std::string::iterator iter = std::find(temp.begin(), temp.end(), a[i]);
        if (iter != temp.end())
        {
            temp.erase(iter);
            ++count;
        }
    }

    std::cout << a.length() + b.length() - count * 2 << std::endl;

    return 0;
}
