#include <iostream>
#include <cstring>
#include <string>

int main()
{
    int a, b, c;

    std::cin >> a >> b >> c;

    int multiply = a * b * c;

    int count[10];
    memset(count, 0, sizeof(count));

    std::string number_string = std::to_string(multiply);

    for (size_t i = 0; i < number_string.length(); ++i)
    {
        ++count[number_string[i] - 48];
    }

    for (int elem : count)
    {
        std::cout << elem << std::endl;
    }

    return 0;
}