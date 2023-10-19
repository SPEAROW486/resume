#include <iostream>
#include <vector>

class Stack
{
public:
    Stack() = default;

    void Push(int n);
    void Pop();
    void Size();
    void Empty();
    void Top();

private:
    std::vector<int> v;
};

int main()
{
    Stack s;

    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string command;
        std::cin >> command;
        if (command == "push")
        {
            int k = 0;
            std::cin >> k;
            s.Push(k);
        }
        else if (command == "pop")
        {
            s.Pop();
        }
        else if (command == "size")
        {
            s.Size();
        }
        else if (command == "empty")
        {
            s.Empty();
        }
        else if (command == "top")
        {
            s.Top();
        }
    }

    return 0;
}

void Stack::Push(int n)
{
    v.push_back(n);
}

void Stack::Pop()
{
    if (!v.empty())
    {
        int number = v.back();
        v.pop_back();
        std::cout << number << std::endl;
    }
    else
    {
        std::cout << "-1" << std::endl;
    }
}

void Stack::Size()
{
    std::cout << v.size() << std::endl;
}

void Stack::Empty()
{
    std::string msg = v.empty() ? "1" : "0";
    std::cout << msg << std::endl;
}

void Stack::Top()
{
    int number = v.empty() ? -1 : v.back();
    std::cout << number << std::endl;
}
