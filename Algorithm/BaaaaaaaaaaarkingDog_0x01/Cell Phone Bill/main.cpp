#include <iostream>
#include <algorithm>

int main()
{
    int number_of_calls = 0;
    std::cin >> number_of_calls;

    int bill_y = 0;
    int bill_m = 0;

    for (int i = 0; i < number_of_calls; ++i)
    {
        int temp = 0;
        std::cin >> temp;
        bill_y += (temp / 30 + 1) * 10;
        bill_m += (temp / 60 + 1) * 15;
    }

    if (bill_y != bill_m)
    {
        bool is_y_small = bill_y < bill_m;
        std::cout << (is_y_small ? "Y" : "M") << " " << std::min(bill_y, bill_m) << std::endl;
    }
    else
    {
        std::cout << "Y M " << bill_y << std::endl;
    }

    return 0;
}