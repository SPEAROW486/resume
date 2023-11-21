#include <iostream>
#include <deque>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::deque<int> q;
    int n = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "push_front")
        {
            int num = 0;
            std::cin >> num;
            q.push_front(num);
        }
        else if (command == "push_back")
        {
            int num = 0;
            std::cin >> num;
            q.push_back(num);
        }
        else if (command == "pop_front")
        {
            if (q.size() == 0)
            {
                std::cout << "-1\n";
                continue;
            }

            int num = q.front();
            q.pop_front();
            std::cout << num << "\n";
        }
        else if (command == "pop_back")
        {
            if (q.size() == 0)
            {
                std::cout << "-1\n";
                continue;
            }

            int num = q.back();
            q.pop_back();
            std::cout << num << "\n";
        }
        else if (command == "size")
        {
            std::cout << q.size() << "\n";
        }
        else if (command == "empty")
        {
            int num = q.empty() ? 1 : 0;
            std::cout << num << "\n";
        }
        else if (command == "front")
        {
            if (q.size() == 0)
            {
                std::cout << "-1\n";
                continue;
            }

            std::cout << q.front() << "\n";
        }
        else if (command == "back")
        {
            if (q.size() == 0)
            {
                std::cout << "-1\n";
                continue;
            }

            std::cout << q.back() << "\n";
        }
    }
}
