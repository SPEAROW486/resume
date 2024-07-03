

#include <iostream>
#include <vector>
#include <random>

void Print(const std::vector<int> &vec)
{
    int i = 0;

    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
        if (++i % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int main()
{
    std::vector<int> v;

    for (int i = 1; i < 101; ++i)
    {
        v.push_back(i);
    }

    std::shuffle(v.begin(), v.end(), std::default_random_engine());

    Print(v);

    std::cout << std::endl;

    for (int i = 0; i < v.size(); ++i)
    {
        int TestingNumber = v[i];
        int Index = i;
        for (int j = i + 1; j < v.size(); ++j)
        {
            // Find Min Number And Save Index
            if (TestingNumber > v[j])
            {
                TestingNumber = v[j];
                Index = j;
            }
        }

        // Swap
        int Temp = v[i];
        v[i] = v[Index];
        v[Index] = Temp;
    }

    Print(v);
    return 0;
}