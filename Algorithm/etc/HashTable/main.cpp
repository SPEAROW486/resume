

#include <iostream>

template <typename T>
class Node
{
public:
    Node(T NewData) : Data(NewData), Next(nullptr) {}
    Node(const std::string &key, T new_data) : Key(key), Data(new_data), Next(nullptr) {}
    virtual ~Node()
    {
        std::cout << "Called Destructor : " << Data << std::endl;
    }

public:
    std::string Key;
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
    void Push_Back(const std::string &key, T Data);
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
void SinglyLinkedList<T>::Push_Back(const std::string &key, T Data)
{
    Node<T> *NodePtr = new Node<T>(key, Data);
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
        std::cout << "Key : " << Ptr->Key << " Data : " << Ptr->Data << std::endl;
        Ptr = Ptr->Next;
    }
}

template <typename T>
class SimpleHashTable
{
public:
    void Push(const std::string &key, T data);
    void Print();

private:
    unsigned long hash(const std::string &str)
    {
        unsigned long hash = 5381;
        for (size_t i = 0; i < str.size(); ++i)
            hash = 33 * hash + (unsigned char)str[i];
        return hash;
    }

    unsigned long SimpleHash(const std::string &str)
    {
        // Collision test
        return 0;
    }

private:
    enum
    {
        BUCKET_SIZE = 5
    };

    SinglyLinkedList<T> Bucket[BUCKET_SIZE];
};

template <typename T>
void SimpleHashTable<T>::Push(const std::string &key, T data)
{
    int idx = SimpleHash(key) % BUCKET_SIZE;

    Bucket[idx].Push_Back(key, data);
}

template <typename T>
void SimpleHashTable<T>::Print()
{
    for (int i = 0; i < BUCKET_SIZE; ++i)
    {
        std::cout << "Bucket " << i << "-" << std::endl;
        Bucket[i].Print();
    }
}

int main()
{
    SimpleHashTable<int> ht;

    ht.Push("HASH", 10);
    ht.Push("SimpleHash", 30);

    ht.Print();
    return 0;
}