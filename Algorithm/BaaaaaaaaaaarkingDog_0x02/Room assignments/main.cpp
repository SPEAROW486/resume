#include <iostream>
#include <vector>

int main()
{
    int students_count = 0;
    int number_one_room = 0;
    std::cin >> students_count >> number_one_room;

    std::vector<std::vector<int>> v(2, std::vector<int>(6, 0));

    for (int i = 0; i < students_count; ++i)
    {
        int sex = 0;
        int grade = 0;

        std::cin >> sex >> grade;

        ++v[sex][grade - 1];
    }

    int count = 0;
    for (const auto &elem : v)
    {
        for (const int temp : elem)
        {
            count += temp / number_one_room;
            if (temp % number_one_room != 0)
            {
                count += 1;
            }
        }
    }

    std::cout << count;

    return 0;
}
