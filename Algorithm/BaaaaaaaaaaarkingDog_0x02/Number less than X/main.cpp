#include <iostream>
#include <vector>

int main()
{
    int n, x;
    std::cin >> n;
    std::cin >> x;

    std::vector<int> candidates;
    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        std::cin >> temp;

        if (temp < x)
        {
            candidates.push_back(temp);
        }
    }

    for (int elem : candidates)
    {
        std::cout << elem << " ";
    }

    return 0;
}