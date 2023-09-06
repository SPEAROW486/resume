

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

void Merge(std::vector<int> &vec, int start, int end)
{
    int middle = (start + end) / 2;
    int left = start;
    int right = middle + 1;
    int k = start;

    std::vector<int> temp(end + 1);

    while (k <= end)
    {
        if (left > middle)
        {
            temp[k++] = vec[right++];
            continue;
        }

        if (right > end)
        {
            temp[k++] = vec[left++];
            continue;
        }

        if (vec[left] <= vec[right])
        {
            temp[k++] = vec[left++];
        }
        else
        {
            temp[k++] = vec[right++];
        }
    }

    for (int i = start; i <= end; ++i)
    {
        vec[i] = temp[i];
    }
}

void MergeSort(std::vector<int> &vec, int start, int end)
{
    if (end > start)
    {
        // divide run
        int middle = (start + end) / 2;

        MergeSort(vec, start, middle);
        MergeSort(vec, middle + 1, end);
        Merge(vec, start, end);
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

    MergeSort(v, 0, v.size() - 1);

    Print(v);
    return 0;
}