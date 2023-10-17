#include <iostream>
#include <list>

#include <sstream>

int main()
{
    int n = 7;
    int k = 3;

    // std::cin >> n;

    std::list<int> list;
    for (int i = 1; i <= n; ++i)
    {
        list.push_back(i);
    }

    std::list<int> josephus;
    for (auto iter = list.begin(); list.size() != 0;)
    {
        for (int i = 0; i < k - 1;)
        {
            ++iter;
            if (iter != list.end())
            {
                ++i;
            }
        }
        josephus.push_back(*iter);
        iter = list.erase(iter);
        if (iter == list.end())
        {
            ++iter;
        }
    }

    //
    // if (!ints.empty())
    // {
    //     iterator it = ints.begin();
    //     const iterator end = ints.end();

    //     cout << *it;
    //     for (++it; it != end; ++it)
    //     {
    //         cout << ", " << *it;
    //     }
    //     cout << std::endl;
    // }

    // 1 2 3 4 5 6 7

    // 1 2 4 5 6 7
    // 1 2 4 5 7
    // 1 4 5 7
    // 1 4 5
    for (const int elem : josephus)
    {
        std::cout << elem << " ";
    }

    return 0;
}