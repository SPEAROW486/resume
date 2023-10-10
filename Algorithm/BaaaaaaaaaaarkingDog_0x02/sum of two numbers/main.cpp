#include <iostream>
#include <vector>
#include <algorithm>

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

    int left = 0;
    int right = n - 1;
    int count = 0;

    std::sort(sequence.begin(), sequence.end());
    while (left < right)
    {
        int sum = sequence[left] + sequence[right];
        if (sum == x)
        {
            ++count;
            ++left;
            --right;
        }
        else if (sum < x)
        {
            ++left;
        }
        else if (sum > x)
        {
            --right;
        }
    }

    std::cout << count;
    return 0;
}
