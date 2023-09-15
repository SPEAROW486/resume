

#include <iostream>
#include <time.h>

int main()
{
    constexpr int MAX = 1000;

    srand(static_cast<unsigned int>(time(NULL)));
    int num = rand() % 1000;

    std::cout << "Number is " << num << std::endl;

    int sum = 0;
    int count = 0;

    num = 4;
    for (int i = 0; i <= MAX; ++i)
    {
        if (i % num == 0)
        {
            sum += i;
            count++;
        }
    }

    std::cout << num << " Multiple Count : " << count << " Multiple Sum : " << sum << std::endl;
    return 0;
}