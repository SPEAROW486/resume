

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
    std::shared_ptr<Node<T>> Next;
};

template <typename T>
class Queue
{
public:
    Queue() : Front(nullptr), Rear(Front) {}

    virtual ~Queue();

    void Push(T Data);
    void Pop();
    T &Peek();
    void Print();

private:
    std::shared_ptr<Node<T>> Front;
    std::weak_ptr<Node<T>> Rear;
};

template <typename T>
Queue<T>::~Queue()
{
    while (Front)
    {
        Front = std::move(Front->Next);
    }
}

template <typename T>
void Queue<T>::Push(T Data)
{
    std::shared_ptr<Node<T>> NodePtr = std::make_shared<Node<T>>(Data);
    std::shared_ptr<Node<T>> LockPtr = Rear.lock();
    if (LockPtr == nullptr)
    {
        Front = std::move(NodePtr);
        Rear = Front;
    }
    else
    {
        LockPtr->Next = std::move(NodePtr);
        Rear = NodePtr;
    }
}

template <typename T>
void Queue<T>::Pop()
{
    assert(Front);
    Front = std::move(Front->Next);
}

template <typename T>
T &Queue<T>::Peek()
{
    assert(Front);
    return *Front->Data;
}

template <typename T>
void Queue<T>::Print()
{
    Node<T> *Ptr = Front.get();
    while (Ptr != nullptr)
    {
        std::cout << "Data : " << *Ptr->Data << std::endl;
        Ptr = Ptr->Next.get();
    }
}

int main()
{
    Queue<int> IntQueue;
    IntQueue.Push(10);
    IntQueue.Push(20);

    IntQueue.Print();

    std::cout << IntQueue.Peek() << std::endl;
    IntQueue.Pop();
    IntQueue.Print();

    return 0;
}