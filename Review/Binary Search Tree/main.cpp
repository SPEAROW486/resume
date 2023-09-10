

#include <iostream>
#include <memory>
#include <stack>
#include <queue>
#include <string>

template <typename T>
class Node
{
public:
    Node(T NewKey) : Key(std::make_unique<T>(NewKey)), Left(nullptr), Right(nullptr) {}
    virtual ~Node()
    {
        std::cout << "Called Destructor : " << *Key.get() << std::endl;
    }

    bool IsKeyEqual(T OtherKey)
    {
        return *Key == OtherKey;
    }

    const T &GetKey() const
    {
        return *Key;
    }

    void SetKey(T NewKey)
    {
        Key.reset();
        Key = std::make_unique<T>(NewKey);
    }

public:
    std::unique_ptr<T> Key;
    std::shared_ptr<Node<T>> Left;
    std::shared_ptr<Node<T>> Right;
    std::weak_ptr<Node<T>> Parent;
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : Root(nullptr) {}
    virtual ~BinarySearchTree();

    void Insert(T Key);
    void Delete(T Key);
    void Print();

private:
    void Clean(std::shared_ptr<Node<T>> NodePtr);
    std::shared_ptr<Node<T>> CreateNode(T Key);
    void PreOrder(std::shared_ptr<Node<T>> NodePtr);
    void InOrder(std::shared_ptr<Node<T>> NodePtr);
    void PostOrder(std::shared_ptr<Node<T>> NodePtr);
    void LevelOrder(std::shared_ptr<Node<T>> NodePtr);

    std::shared_ptr<Node<T>> Delete_Internel(std::shared_ptr<Node<T>> NodePtr, T Key);

    std::shared_ptr<Node<T>> FindNode(std::shared_ptr<Node<T>> NodePtr, T Key);

private:
    std::shared_ptr<Node<T>> Root;
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    Clean(Root);
}

template <typename T>
void BinarySearchTree<T>::Clean(std::shared_ptr<Node<T>> NodePtr)
{
    if (NodePtr == nullptr)
    {
        return;
    }

    Clean(NodePtr->Left);
    Clean(NodePtr->Right);
    NodePtr = nullptr;
}

template <typename T>
std::shared_ptr<Node<T>> BinarySearchTree<T>::CreateNode(T Key)
{
    std::shared_ptr<Node<T>> NewNode = std::make_shared<Node<T>>(Key);
    return NewNode;
}

template <typename T>
void BinarySearchTree<T>::PreOrder(std::shared_ptr<Node<T>> NodePtr)
{
    // A B D E C F G
    if (NodePtr == nullptr)
    {
        return;
    }

    std::cout << *NodePtr->Key << " ";
    PreOrder(NodePtr->Left);
    PreOrder(NodePtr->Right);
}

template <typename T>
void BinarySearchTree<T>::PostOrder(std::shared_ptr<Node<T>> NodePtr)
{
    // D E B F G C A
    if (NodePtr == nullptr)
    {
        return;
    }

    PostOrder(NodePtr->Left);
    PostOrder(NodePtr->Right);
    std::cout << *NodePtr->Key << " ";
}

template <typename T>
void BinarySearchTree<T>::InOrder(std::shared_ptr<Node<T>> NodePtr)
{
    // D B E A F C G
    if (NodePtr == nullptr)
    {
        return;
    }

    InOrder(NodePtr->Left);
    std::cout << *NodePtr->Key << " ";
    InOrder(NodePtr->Right);
}
template <typename T>
void BinarySearchTree<T>::LevelOrder(std::shared_ptr<Node<T>> NodePtr)
{
    // A B C D E F G
    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(NodePtr);

    while (!q.empty())
    {
        std::shared_ptr<Node<T>> Temp = q.front();
        q.pop();

        std::cout << *Temp->Key << " ";
        if (Temp->Left != nullptr)
        {
            q.push(Temp->Left);
        }

        if (Temp->Right != nullptr)
        {
            q.push(Temp->Right);
        }
    }
}

template <typename T>
std::shared_ptr<Node<T>> BinarySearchTree<T>::Delete_Internel(std::shared_ptr<Node<T>> NodePtr, T Key)
{
    if (NodePtr == nullptr)
    {
        return nullptr;
    }

    if (NodePtr->GetKey() > Key)
    {
        NodePtr->Left = Delete_Internel(NodePtr->Left, Key);
    }
    else
    {
        NodePtr->Right = Delete_Internel(NodePtr->Right, Key);
    }

    if (NodePtr->GetKey() != Key)
    {
        return NodePtr;
    }

    if (NodePtr->Left == nullptr)
    {
        std::shared_ptr<Node<T>> temp = NodePtr->Right;
        NodePtr = nullptr;
        return temp;
    }
    else if (NodePtr->Right == nullptr)
    {
        std::shared_ptr<Node<T>> temp = NodePtr->Left;
        NodePtr = nullptr;
        return temp;
    }
    else
    {
        // both
        // 왼쪽 서브 트리면 가장 큰 값
        // 오른쪽 서브 트리면 가장 작은 값을 찾아야하는데..
        // 중위 계승자..?
        std::shared_ptr<Node<T>> succ = NodePtr;
        std::shared_ptr<Node<T>> succ_parent = nullptr;

        while (succ->Left != nullptr)
        {
            succ_parent = succ;
            succ = succ->Left;
        }

        std::shared_ptr<Node<T>> ret = nullptr;
        if (succ->GetKey() <= NodePtr->Left->GetKey() && NodePtr->Right->GetKey() > succ->GetKey())
        {
            ret = succ;
        }
        else
        {
            ret = succ_parent->Right;
        }

        ret->Left = NodePtr->Left;
        ret->Right = NodePtr->Right;

        NodePtr->Left = nullptr;
        NodePtr->Right = nullptr;
        NodePtr = nullptr;

        return ret;
    }
}

template <typename T>
std::shared_ptr<Node<T>> BinarySearchTree<T>::FindNode(std::shared_ptr<Node<T>> NodePtr, T Key)
{
    if (NodePtr == nullptr)
    {
        return nullptr;
    }

    if (NodePtr->GetKey() == Key)
    {
        return NodePtr;
    }

    if (NodePtr->GetKey() > Key)
    {
        return FindNode(NodePtr->Left, Key);
    }
    else
    {
        return FindNode(NodePtr->Right, Key);
    }
}

template <typename T>
void BinarySearchTree<T>::Insert(T Key)
{
    std::shared_ptr<Node<T>> NewNode = CreateNode(Key);

    if (Root == nullptr)
    {
        Root = NewNode;
    }
    else
    {
        std::shared_ptr<Node<T>> Temp = Root;
        std::shared_ptr<Node<T>> Ptr = nullptr;
        while (Temp != nullptr)
        {
            Ptr = Temp;
            if (Temp->GetKey() > Key)
            {
                Temp = Temp->Left;
            }
            else
            {
                Temp = Temp->Right;
            }
        }

        if (Ptr->GetKey() > Key)
        {
            NewNode->Parent = Ptr;
            Ptr->Left = NewNode;
        }
        else
        {
            NewNode->Parent = Ptr;
            Ptr->Right = NewNode;
        }
    }
}

template <typename T>
void BinarySearchTree<T>::Delete(T Key)
{
    assert(Root);
    Delete_Internel(Root, Key);
}

template <typename T>
void BinarySearchTree<T>::Print()
{
    assert(Root);
    InOrder(Root);
    std::cout << std::endl;
}

int main()
{
    BinarySearchTree<int> bst;

    bst.Insert(15);
    bst.Insert(7);
    bst.Insert(3);
    bst.Insert(8);
    bst.Insert(1);
    bst.Insert(4);

    bst.Print();

    bst.Delete(7);

    bst.Print();

    return 0;
}