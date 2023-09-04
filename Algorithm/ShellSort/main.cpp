

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

    for (int gap = v.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < v.size(); ++i)
        {
            int Key = v[i];

            int j;
            // 갭 만큼 멀리 있는 요소의 값과 비교해서 찾으면 스왑
            // 못 찾으면 >> 쪽으로 한칸 이동 후 또 갭 만큼 멀리있는 요소와 값을 비교
            for (j = i; j >= gap && v[j - gap] > Key; j -= gap)
            {
                v[j] = v[j - gap];
            }
            v[j] = Key;
        }
    }
    Print(v);
    return 0;
}