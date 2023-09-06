

#include <iostream>
#include <vector>
#include <queue>
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

int GetMax(const std::vector<int> &vec)
{
    int max = vec[0];

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
}

void RadixSort(std::vector<int> &vec)
{
    int max = GetMax(vec);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        std::vector<std::queue<int>> qList(10);
        for (int i = 0; i < vec.size(); ++i)
        {
            int bucketIndex = (vec[i] / exp) % 10;
            qList[bucketIndex].push(vec[i]);
        }

        int index = 0;
        for (int j = 0; j < 10; ++j)
        {
            while (!qList[j].empty())
            {
                vec[index++] = qList[j].front();
                qList[j].pop();
            }
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

    RadixSort(v);

    Print(v);
    return 0;
}