
#include <bits/stdc++.h>

bool IsPalindrome(int i)
{
    std::string str = std::to_string(i);

    bool result = true;
    for (int i = 0; i < str.length() / 2; ++i)
    {
        char c1 = str[i];
        char c2 = str[str.length() - 1 - i];

        result &= c1 == c2;
    }
    return result;
}

int main()
{

    while (true)
    {
        int n;
        std::cin >> n;

        if (n == 0)
        {
            break;
        }

        bool result = IsPalindrome(n);
        std::string s = result ? "yes\n" : "no\n";
        std::cout << s;
    }

    return 0;
}