

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
        return NodePtr;
    }
    else if (NodePtr->GetKey() < Key)
    {
        NodePtr->Right = Delete_Internel(NodePtr->Right, Key);
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
        // 지우려고 하는 노드의 우측 서브 트리를 뒤진다.
        // 계승자의 레프트가 비어있을떄 까지 뒤진다.
        // 다 뒤지고 나면
        // 지우려고 하는 노드랑 계승자의 부모가 같은지 아닌지에 따라
        // 포인터를 바꿔주는 부분이 다름.
        // 그 후 지울 노드에 계승자의 값을 카피하고 계승자를 삭제
        std::shared_ptr<Node<T>> succ_parent = NodePtr;
        std::shared_ptr<Node<T>> succ = succ_parent->Right;

        while (succ->Left != nullptr)
        {
            succ_parent = succ;
            succ = succ->Left;
        }

        if (succ_parent != NodePtr)
        {
            succ_parent->Left = succ->Right;
        }
        else
        {
            succ_parent->Right = succ->Right;
        }

        NodePtr->SetKey(succ->GetKey());
        succ = nullptr;

        return NodePtr;
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

    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(70);
    bst.Insert(60);
    bst.Insert(80);

    bst.Print();

    bst.Delete(70);

    bst.Print();

    return 0;
}