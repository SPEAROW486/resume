

#include <iostream>
#include <memory>

template <typename T>
class Node
{
public:
    Node(T NewData) : Data(std::make_unique<T>(NewData)), Next(nullptr) {}
    virtual ~Node()
    {
        std::cout << "Called Destructor : " << *Data.get() << std::endl;
    }

public:
    std::unique_ptr<T> Data;
    std::unique_ptr<Node<T>> Next;
};

template <typename T>
class Stack
{
public:
    Stack() : Top(nullptr) {}

    virtual ~Stack();

    void Push(T Data);
    void Pop();
    T &Peek();
    void Print();

private:
    std::unique_ptr<Node<T>> Top;
};

template <typename T>
Stack<T>::~Stack()
{
    while (Top)
    {
        Top = std::move(Top->Next);
    }
}

template <typename T>
void Stack<T>::Push(T Data)
{
    std::unique_ptr<Node<T>> NodePtr = std::make_unique<Node<T>>(Data);
    if (Top == nullptr)
    {
        Top = std::move(NodePtr);
    }
    else
    {
        NodePtr->Next = std::move(Top);
        Top = std::move(NodePtr);
    }
}

template <typename T>
void Stack<T>::Pop()
{
    assert(Top);
    Top = std::move(Top->Next);
}

template <typename T>
T &Stack<T>::Peek()
{
    assert(Top);
    return *Top->Data;
}

template <typename T>
void Stack<T>::Print()
{
    Node<T> *Ptr = Top.get();
    while (Ptr != nullptr)
    {
        std::cout << "Data : " << *Ptr->Data << std::endl;
        Ptr = Ptr->Next.get();
    }
}

int main()
{
    Stack<int> IntStack;
    IntStack.Push(10);
    IntStack.Push(20);

    IntStack.Print();

    std::cout << "Peek : " << IntStack.Peek() << std::endl;
    IntStack.Pop();

    IntStack.Print();
    return 0;
}