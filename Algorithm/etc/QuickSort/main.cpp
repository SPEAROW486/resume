

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

int Partition(std::vector<int> &vec, int begin, int end)
{
    int pivot = vec[end];
    int i = begin - 1;
    int j = end;

    while (true)
    {
        while (vec[++i] < pivot)
        {
        }

        while (vec[--j] > pivot)
        {
        }

        if (i >= j)
        {
            break;
        }

        std::swap(vec[i], vec[j]);
    }

    std::swap(vec[i], vec[end]);

    return i;
}

void QuickSort(std::vector<int> &vec, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int pivot = Partition(vec, begin, end);

    QuickSort(vec, begin, pivot - 1);
    QuickSort(vec, pivot + 1, end);
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

    QuickSort(v, 0, v.size() - 1);

    Print(v);
    return 0;
}