

#include <iostream>
#include <memory>

template <typename T>
class Node
{
public:
    Node(T NewData) : Data(std::make_unique<T>(NewData)), Next(nullptr), Prev(Next) {}
    virtual ~Node()
    {
        std::cout << "Called Destructor : " << *Data.get() << std::endl;
    }

    std::weak_ptr<Node<T>> &operator++()
    {
        return Next;
    }

public:
    std::unique_ptr<T> Data;
    std::shared_ptr<Node<T>> Next;
    std::weak_ptr<Node<T>> Prev;
};

template <typename T>
class DoublyLinkedList;

template <typename T>
class MyIterator
{
public:
    friend DoublyLinkedList<T>;

    MyIterator() = default;
    MyIterator(std::weak_ptr<Node<T>> Iter) : Ptr(Iter) {}

    MyIterator &operator++()
    {
        std::shared_ptr<Node<T>> shared = Ptr.lock();
        assert(shared);
        Ptr = shared->Next;
        return *this;
    }

    MyIterator operator++(int n)
    {
        MyIterator Temp = *this;
        std::shared_ptr<Node<T>> shared = Temp.Ptr.lock();
        assert(shared);
        Temp.Ptr = shared->Next;
        return Temp;
    }

private:
    std::weak_ptr<Node<T>> Ptr;
};

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : Head(nullptr), Tail(Head) {}

    virtual ~DoublyLinkedList();

    void Push_Front(T Data);
    void Push_Back(T Data);
    void Pop_Front();
    void Pop_Back();
    void Insert(T Data, MyIterator<T> Iter);
    void Erase(MyIterator<T> Iter);
    void Print();

    T &Front();
    T &Back();

    MyIterator<T> Begin()
    {
        assert(Head);
        return MyIterator<T>(Head);
    }

    MyIterator<T> End()
    {
        assert(Tail);
        return MyIterator<T>(Tail);
    }

private:
    std::shared_ptr<Node<T>> Head;
    std::weak_ptr<Node<T>> Tail;
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
}

template <typename T>
void DoublyLinkedList<T>::Push_Front(T Data)
{
    std::shared_ptr<Node<T>> NodePtr = std::make_shared<Node<T>>(Data);

    if (Head == nullptr)
    {
        Head = NodePtr;
        Tail = NodePtr;
    }
    else
    {
        Head->Prev = NodePtr;
        NodePtr->Next = Head;
        Head = NodePtr;
    }
}

template <typename T>
void DoublyLinkedList<T>::Push_Back(T Data)
{
    std::shared_ptr<Node<T>> NodePtr = std::make_shared<Node<T>>(Data);

    if (Head == nullptr)
    {
        Head = NodePtr;
        Tail = NodePtr;
    }
    else
    {
        std::shared_ptr<Node<T>> TailLockPtr = Tail.lock();
        assert(TailLockPtr);

        TailLockPtr->Next = NodePtr;
        NodePtr->Prev = Tail;
        Tail = NodePtr;
    }
}

template <typename T>
void DoublyLinkedList<T>::Pop_Front()
{
    assert(Head);
    Head = Head->Next;
}

template <typename T>
void DoublyLinkedList<T>::Pop_Back()
{
    std::shared_ptr<Node<T>> TailLockPtr = Tail.lock();
    assert(TailLockPtr);

    std::shared_ptr<Node<T>> PrevLockPtr = TailLockPtr->Prev.lock();
    assert(PrevLockPtr);

    Tail = PrevLockPtr;
    PrevLockPtr->Next = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::Insert(T Data, MyIterator<T> Iter)
{
    // insert before iter

    std::shared_ptr<Node<T>> NodePtr = std::make_shared<Node<T>>(Data);
    std::shared_ptr<Node<T>> LockPtr = Iter.Ptr.lock();

    if (LockPtr == Head)
    {
        NodePtr->Next = LockPtr;
        Head->Prev = NodePtr;
        Head = NodePtr;
    }
    else
    {
        std::shared_ptr<Node<T>> PrevPtr = LockPtr->Prev.lock();
        PrevPtr->Next = NodePtr;
        NodePtr->Prev = PrevPtr;

        NodePtr->Next = LockPtr;
        LockPtr->Prev = NodePtr;
    }
}

template <typename T>
void DoublyLinkedList<T>::Erase(MyIterator<T> Iter)
{
    // remove iter postion node

    std::shared_ptr<Node<T>> LockPtr = Iter.Ptr.lock();
    std::shared_ptr<Node<T>> PrevPtr = LockPtr->Prev.lock();

    PrevPtr->Next = LockPtr->Next;
    LockPtr = nullptr;
}

template <typename T>
T &DoublyLinkedList<T>::Front()
{
    assert(Head);
    return *Head->Data;
}

template <typename T>
T &DoublyLinkedList<T>::Back()
{
    std::shared_ptr<Node<T>> LockPtr = Tail.lock();
    assert(LockPtr);
    return *LockPtr->Data;
}

template <typename T>
void DoublyLinkedList<T>::Print()
{
    std::shared_ptr<Node<T>> Ptr = Head;
    while (Ptr != nullptr)
    {
        std::cout << "Data : " << *Ptr->Data << ", " << Ptr << std::endl;
        Ptr = Ptr->Next;
    }

    std::cout << "Head : " << Head << " Tail : " << Tail.lock() << std::endl;
}

int main()
{
    DoublyLinkedList<int> List;

    List.Push_Back(10);

    List.Push_Back(30);
    auto iter = List.Begin();

    ++iter;

    List.Insert(20, iter);

    return 0;
}