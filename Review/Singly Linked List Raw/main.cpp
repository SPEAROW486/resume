

#include <iostream>

template <typename T>
class Node
{
public:
    Node(T NewData) : Data(NewData), Next(nullptr) {}
    virtual ~Node()
    {
        std::cout << "Called Destructor : " << Data << std::endl;
    }

public:
    T Data;
    Node *Next;
};

template <typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : Head(nullptr) {}

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
    Node<T> *Head;
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (Head)
    {
        Node<T> *DeleteNodePtr = Head;
        Head = Head->Next;
        delete DeleteNodePtr;
    }
}

template <typename T>
void SinglyLinkedList<T>::Push_Front(T Data)
{
    Node<T> *NodePtr = new Node<T>(Data);

    if (Head == nullptr)
    {
        Head = NodePtr;
    }
    else
    {
        NodePtr->Next = Head;
        Head = NodePtr;
    }
}

template <typename T>
void SinglyLinkedList<T>::Push_Back(T Data)
{
    Node<T> *NodePtr = new Node<T>(Data);
    if (Head == nullptr)
    {
        Head = NodePtr;
    }
    else
    {
        Node<T> *Current = Head;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        Current->Next = NodePtr;
    }
}

template <typename T>
void SinglyLinkedList<T>::Pop_Front()
{
    assert(Head);

    Node<T> *DeleteNodePtr = Head;
    Head = Head->Next;
    delete DeleteNodePtr;
}

template <typename T>
void SinglyLinkedList<T>::Pop_Back()
{
    assert(Head);

    Node<T> *Current = Head;
    Node<T> *Prev = Current;

    while (Current->Next != nullptr)
    {
        Prev = Current;
        Current = Current->Next;
    }

    if (Current == Head)
    {
        delete Current;
        Head = nullptr;
    }
    else
    {
        delete Current;
        Prev->Next = nullptr;
    }
}

template <typename T>
void SinglyLinkedList<T>::Insert(T Data, int Index)
{
    Node<T> *NodePtr = new Node<T>(Data);

    if (Head == nullptr)
    {
        Head = NodePtr;
    }
    else
    {
        Node<T> *Current = Head;
        Node<T> *Prev = Current;

        for (int i = 0; i < Index; ++i)
        {
            Prev = Current;
            Current = Current->Next;
        }

        Prev->Next = NodePtr;
        NodePtr->Next = Current;
    }
}

template <typename T>
void SinglyLinkedList<T>::Erase(int Index)
{
    if (Index == 0)
    {
        // remove head
        Node<T> *Current = Head;
        Head = Head->Next;
        delete Current;
    }
    else
    {
        Node<T> *Current = Head;
        Node<T> *Prev = Current;

        for (int i = 0; i < Index; ++i)
        {
            Prev = Current;
            Current = Current->Next;
        }

        Prev->Next = Current->Next;
        delete Current;
        Current = nullptr;
    }
}

template <typename T>
T &SinglyLinkedList<T>::Front()
{
    assert(Head);
    return Head->Data;
}

template <typename T>
T &SinglyLinkedList<T>::Back()
{
    assert(Head);

    Node<T> *Current = Head;
    while (Current->Next != nullptr)
    {
        Current = Current->Next;
    }

    return Current->Data;
}

template <typename T>
void SinglyLinkedList<T>::Print()
{
    Node<T> *Ptr = Head;
    while (Ptr != nullptr)
    {
        std::cout << "Data : " << Ptr->Data << std::endl;
        Ptr = Ptr->Next;
    }
}

int main()
{
    SinglyLinkedList<int> List;

    List.Push_Back(10);
    List.Push_Back(20);
    List.Push_Back(30);

    std::cout << "Front : " << List.Front() << " Back : " << List.Back() << std::endl;

    return 0;
}