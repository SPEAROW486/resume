
#include <bits/stdc++.h>

class DualPriorityQueue
{
public:
    DualPriorityQueue()
    {
    }

    virtual ~DualPriorityQueue()
    {
    }

    void Insert(int n)
    {
        max_heap.push(n);
        min_heap.push(n);
        freq[n]++;
    }

    void DeleteMax()
    {
        if (!max_heap.empty())
        {
            int max = max_heap.top();
            max_heap.pop();
            freq[max]--;
        }
        CleanUp();
    }

    void DeleteMin()
    {
        if (!min_heap.empty())
        {
            int min = min_heap.top();
            min_heap.pop();
            freq[min]--;
        }
        CleanUp();
    }

    void CleanUp()
    {
        while (!max_heap.empty() && freq[max_heap.top()] == 0)
        {
            max_heap.pop();
        }

        while (!min_heap.empty() && freq[min_heap.top()] == 0)
        {
            min_heap.pop();
        }
    }

    void Dump()
    {
        if (max_heap.size() == 0 || min_heap.size() == 0)
        {
            std::cout << "EMPTY\n";
        }
        else
        {
            std::cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }

private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    std::unordered_map<int, int> freq;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        DualPriorityQueue dpq;

        int n;
        std::cin >> n;

        for (int i = 0; i < n; ++i)
        {
            std::string cmd;
            int number;

            std::cin >> cmd >> number;

            if (cmd == "I")
            {
                dpq.Insert(number);
            }
            else if (cmd == "D")
            {
                if (number == 1)
                {
                    dpq.DeleteMax();
                }
                else
                {
                    dpq.DeleteMin();
                }
            }
        }

        dpq.Dump();
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}