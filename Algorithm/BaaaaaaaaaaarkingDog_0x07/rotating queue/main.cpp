#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::deque<int> deq;

    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        deq.push_back(i + 1);
    }

    int number_operations = 0;
    for (int i = 0; i < m; ++i)
    {
        int num = 0;
        std::cin >> num;

        auto it = std::find(deq.begin(), deq.end(), num);
        int left_distance = std::distance(deq.begin(), it);
        int right_distance = abs(std::distance(deq.end(), it));

        if (left_distance < right_distance)
        {
            while (true)
            {
                if (deq.front() == num)
                {
                    deq.pop_front();
                    break;
                }
                else
                {
                    deq.push_back(deq.front());
                    deq.pop_front();
                    ++number_operations;
                }
            }
        }
        else
        {
            while (true)
            {
                if (deq.front() == num)
                {
                    deq.pop_front();
                    break;
                }
                else
                {
                    deq.push_front(deq.back());
                    deq.pop_back();
                    ++number_operations;
                }
            }
        }
    }

    std::cout << number_operations;
}
