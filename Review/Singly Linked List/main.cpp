

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
    std::unique_ptr<Node> Next;
};

template <typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : Head(nullptr), Size(0) {}

    virtual ~SinglyLinkedList();

    void Push_Front(T Data);
    void Push_Back(T Data);
    void Pop_Front();
    void Pop_Back();
    void Insert(T Data, int Index);
    void Erase(int Index);
    void Print();

    T &Front();
    T &Back();

private:
    std::unique_ptr<Node<T>> Head;
    size_t Size;
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (Head)
    {
        Head = std::move(Head->Next);
    }
    Size = 0;
}

template <typename T>
void SinglyLinkedList<T>::Push_Front(T Data)
{
    std::unique_ptr<Node<T>> NodePtr = std::make_unique<Node<T>>(Data);

    if (Head == nullptr)
    {
        Head = std::move(NodePtr);
    }
    else
    {
        NodePtr->Next = std::move(Head);
        Head = std::move(NodePtr);
    }
}

template <typename T>
void SinglyLinkedList<T>::Push_Back(T Data)
{
    std::unique_ptr<Node<T>> NodePtr = std::make_unique<Node<T>>(Data);
    if (Head == nullptr)
    {
        Head = std::move(NodePtr);
    }
    else
    {
        Node<T> *Ptr = Head.get();
        while (Ptr->Next != nullptr)
        {
            Ptr = Ptr->Next.get();
        }
        Ptr->Next = std::move(NodePtr);
    }
}

template <typename T>
void SinglyLinkedList<T>::Pop_Front()
{
    assert(Head);
    Head = std::move(Head->Next);
}

template <typename T>
void SinglyLinkedList<T>::Pop_Back()
{
    assert(Head);

    Node<T> *Current = Head.get();
    Node<T> *Prev = Current;
    while (Current->Next != nullptr)
    {
        Prev = Current;
        Current = Current->Next.get();
    }

    if (Current == Prev)
    {
        Head = nullptr;
    }
    else
    {
        Prev->Next = nullptr;
    }
}

template <typename T>
void SinglyLinkedList<T>::Insert(T Data, int Index)
{
    std::unique_ptr<Node<T>> NodePtr = std::make_unique<Node<T>>(Data);

    if (Head == nullptr)
    {
        Head = std::move(NodePtr);
    }
    else
    {
        Node<T> *Current = Head.get();
        Node<T> *Prev = Current;
        for (int i = 0; i < Index; ++i)
        {
            Prev = Current;
            Current = Current->Next.get();
        }

        NodePtr->Next = std::move(Prev->Next);
        Prev->Next = std::move(NodePtr);
    }
}

template <typename T>
void SinglyLinkedList<T>::Erase(int Index)
{
    if (Index == 0)
    {
        Head = std::move(Head->Next);
    }
    else
    {
        Node<T> *Current = Head.get();
        Node<T> *Prev = Current;
        for (int i = 0; i < Index; i++)
        {
            Prev = Current;
            Current = Current->Next.get();
        }

        Prev->Next = std::move(Current->Next);
        Current = nullptr;
    }
}

template <typename T>
T &SinglyLinkedList<T>::Front()
{
    return *Head->Data;
}

template <typename T>
T &SinglyLinkedList<T>::Back()
{
    Node<T> *Current = Head.get();
    Node<T> *Prev = Current;

    while (Current->Next != nullptr)
    {
        Prev = Current;
        Current = Current->Next.get();
    }

    if (Current == Prev)
    {
        return *Head->Data;
    }
    else
    {
        return *Prev->Next->Data;
    }
}

template <typename T>
void SinglyLinkedList<T>::Print()
{
    Node<T> *Ptr = Head.get();
    while (Ptr != nullptr)
    {
        std::cout << "Data : " << *Ptr->Data << std::endl;
        Ptr = Ptr->Next.get();
    }
}

int main()
{
    SinglyLinkedList<int> List;

    List.Insert(30, 0);
    List.Insert(40, 1);
    List.Erase(1);
    List.Print();

    return 0;
}