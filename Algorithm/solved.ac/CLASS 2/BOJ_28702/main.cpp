
#include <bits/stdc++.h>

std::string buf[3];
int numbers[3];

bool IsNumber(const std::string &s, int &number)
{
    try
    {
        number = std::stoi(s);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> buf[0] >> buf[1] >> buf[2];

    int number = 0;
    if (IsNumber(buf[0], number))
    {
        numbers[0] = number;
        numbers[1] = number + 1;
        numbers[2] = number + 2;
    }
    else if (IsNumber(buf[1], number))
    {
        numbers[0] = number - 1;
        numbers[1] = number;
        numbers[2] = number + 1;
    }
    else if (IsNumber(buf[2], number))
    {
        numbers[0] = number - 2;
        numbers[1] = number - 1;
        numbers[2] = number;
    }

    int result = numbers[2] + 1;
    if (result % 15 == 0)
    {
        std::cout << "FizzBuzz" << "\n";
    }
    else if (result % 3 == 0)
    {
        std::cout << "Fizz" << "\n";
    }
    else if (result % 5 == 0)
    {
        std::cout << "Buzz" << "\n";
    }
    else
    {
        std::cout << result << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}