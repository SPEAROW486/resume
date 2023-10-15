#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int room_number;
    std::cin >> room_number;

    int numbers[10] = {0};

    std::string word = std::to_string(room_number);
    for (size_t i = 0; i < word.length(); ++i)
    {
        ++numbers[word[i] - 48];
    }

    int temp = numbers[6];
    numbers[6] = (temp + numbers[9]) / 2;
    numbers[9] = (temp + numbers[9]) - numbers[6];

    std::cout << *std::max_element(numbers, numbers + 10);

    return 0;
}