#include <iostream>
#include <deque>
#include <algorithm>

void Initialize(std::string s, std::deque<int> &d)
{
    int previous = 0;
    int current = 0;

    s.erase(s.begin());
    s.erase(--s.end());

    current = s.find(',');
    // find는 찾을게 없으면 npos를 리턴함
    while (current != std::string::npos)
    {
        std::string substring = s.substr(previous, current - previous);
        d.push_back(std::stoi(substring));
        previous = current + 1;
        current = s.find(',', previous);
    }

    if (!s.empty())
    {
        d.push_back(std::stoi(s.substr(previous, current - previous)));
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int tc = 0;
    std::cin >> tc;

    for (int i = 0; i < tc; ++i)
    {
        std::deque<int> deq;
        bool front = true;
        bool error = false;

        std::string p;
        std::cin >> p;

        int n = 0;
        std::cin >> n; // 이 n을 입력받는 이유를 모르겠음 예를 쓸떄가 있나?
        // seq안에 들어있는 수의 개수인데 ? 쓸모가??

        std::string seq;
        std::cin >> seq;

        Initialize(seq, deq);

        for (const auto &c : p)
        {
            if (c == 'R')
            {
                front = !front;
            }

            if (c == 'D')
            {
                if (deq.size() == 0)
                {
                    error = true;
                }
                else
                {
                    if (front)
                    {
                        deq.pop_front();
                    }
                    else
                    {
                        deq.pop_back();
                    }
                }
            }
        }

        if (error)
        {
            std::cout << "error" << std::endl;
        }
        else
        {
            std::cout << "[";
            while (!deq.empty())
            {
                if (front)
                {
                    std::cout << deq.front();
                    deq.pop_front();
                    if (!deq.empty())
                    {
                        std::cout << ",";
                    }
                }
                else
                {
                    std::cout << deq.back();
                    deq.pop_back();
                    if (!deq.empty())
                    {
                        std::cout << ",";
                    }
                }
            }
            std::cout << "]\n";
        }
    }
}
