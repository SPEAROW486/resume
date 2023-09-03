

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

    for (int i = i; i < v.size(); ++i)
    {
        int Key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > Key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = Key;
    }

    Print(v);
    return 0;
}