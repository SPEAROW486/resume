

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
    void Insert(int Index);
    void Erase(int Index);
    void Print();

    std::unique_ptr<Node<T>> &Front();
    std::unique_ptr<Node<T>> &Back();

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
}

template <typename T>
void SinglyLinkedList<T>::Pop_Back()
{
}

template <typename T>
void SinglyLinkedList<T>::Insert(int Index)
{
}

template <typename T>
void SinglyLinkedList<T>::Erase(int Index)
{
}

template <typename T>
std::unique_ptr<Node<T>> &SinglyLinkedList<T>::Front()
{
    return Head;
}

template <typename T>
std::unique_ptr<Node<T>> &SinglyLinkedList<T>::Back()
{
    return Head;
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
    List.Push_Back(30);
    List.Push_Back(40);
    List.Push_Back(50);
    List.Print();

    std::cout << "---------------------" << std::endl;

    List.Push_Front(20);
    List.Push_Front(10);
    List.Print();

    return 0;
}