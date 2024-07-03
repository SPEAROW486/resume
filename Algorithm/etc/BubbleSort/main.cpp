

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

    // { 0 , 1} ~ { i - 1, i } 까지 인접한 요소 끼리 비교
    for (int i = v.size() - 1; i >= 0; --i)
    {

        for (int j = 1; j <= i; ++j)
        {
            if (v[j - 1] > v[j])
            {
                // Swap
                int Temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = Temp;
            }
        }
    }

    Print(v);
    return 0;
}