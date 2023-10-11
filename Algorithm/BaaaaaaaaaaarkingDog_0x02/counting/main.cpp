#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> sequence;
    sequence.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        std::cin >> temp;
        sequence.push_back(temp);
    }

    int x = 0;
    std::cin >> x;

    int count = 0;
    for (const int elem : sequence)
    {
        if (elem == x)
        {
            ++count;
        }
    }

    std::cout << count;
    return 0;
}
