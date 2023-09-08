

#include <iostream>
#include <vector>
#include <random>

int BinarySearch(std::vector<int> &vec, int find, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (find == vec[mid])
    {
        return vec[mid];
    }

    int ret = 0;
    if (find > vec[mid])
    {
        ret = BinarySearch(vec, find, mid + 1, right);
    }
    else
    {
        ret = BinarySearch(vec, find, left, mid - 1);
    }

    return ret;
}

int main()
{
    std::vector<int> v;

    for (int i = 1; i < 101; ++i)
    {
        v.push_back(i);
    }

    std::cout << BinarySearch(v, 34, 0, v.size() - 1);

    return 0;
}