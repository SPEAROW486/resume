#include <iostream>
#include <list>

int main()
{
    int n = 0;
    int k = 0;

    std::cin >> n >> k;

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

    if (!josephus.empty())
    {
        auto it = josephus.begin();
        std::cout << "<" << *it;
        for (++it; it != josephus.end(); ++it)
        {
            std::cout << ", " << *it;
        }
        std::cout << ">" << std::endl;
    }

    return 0;
}