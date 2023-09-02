

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
class BinaryTree
{
public:
    BinaryTree() : Root(nullptr) {}
    virtual ~BinaryTree();

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
    void DeleteDeepestNode(std::shared_ptr<Node<T>> NodePtr);

private:
    std::shared_ptr<Node<T>> Root;
};

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    Clean(Root);
}

template <typename T>
void BinaryTree<T>::Clean(std::shared_ptr<Node<T>> NodePtr)
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
std::shared_ptr<Node<T>> BinaryTree<T>::CreateNode(T Key)
{
    std::shared_ptr<Node<T>> NewNode = std::make_shared<Node<T>>(Key);
    return NewNode;
}

template <typename T>
void BinaryTree<T>::PreOrder(std::shared_ptr<Node<T>> NodePtr)
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
void BinaryTree<T>::PostOrder(std::shared_ptr<Node<T>> NodePtr)
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
void BinaryTree<T>::InOrder(std::shared_ptr<Node<T>> NodePtr)
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
void BinaryTree<T>::LevelOrder(std::shared_ptr<Node<T>> NodePtr)
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
void BinaryTree<T>::Insert(T Key)
{
    if (Root == nullptr)
    {
        Root = CreateNode(Key);
        return;
    }
    else
    {
        std::queue<std::shared_ptr<Node<T>>> q;
        q.push(Root);

        while (!q.empty())
        {
            std::shared_ptr<Node<T>> Temp = q.front();
            q.pop();

            if (Temp->Left != nullptr)
            {
                q.push(Temp->Left);
            }
            else
            {
                Temp->Left = CreateNode(Key);
                return;
            }

            if (Temp->Right != nullptr)
            {
                q.push(Temp->Right);
            }
            else
            {
                Temp->Right = CreateNode(Key);
                return;
            }
        }
    }
}

template <typename T>
void BinaryTree<T>::Delete(T Key)
{
    // Find Key Node
    // Find DeepestNode
    // And Call DeleteDeepestNode
    // Swap KeyNode == cached_DeepestNode_value;

    assert(Root);
    if (Root->Left == nullptr && Root->Right == nullptr)
    {
        if (Root->GetKey() == Key)
        {
            Root = nullptr;
            return;
        }
    }

    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(Root);

    std::shared_ptr<Node<T>> KeyNode(nullptr);
    std::shared_ptr<Node<T>> Temp(nullptr);
    while (!q.empty())
    {
        Temp = q.front();
        q.pop();

        if (Temp->GetKey() == Key)
        {
            KeyNode = Temp;
        }

        if (Temp->Left != nullptr)
        {
            q.push(Temp->Left);
        }

        if (Temp->Right != nullptr)
        {
            q.push(Temp->Right);
        }
    }

    if (KeyNode != nullptr)
    {
        T Cached_Key = Temp->GetKey();
        DeleteDeepestNode(Temp);
        KeyNode->SetKey(Cached_Key);
    }
}

template <typename T>
void BinaryTree<T>::DeleteDeepestNode(std::shared_ptr<Node<T>> NodePtr)
{
    // Find DeleteNode
    // x.Left == DeleteNode ? x.Left = nullptr;
    // x.Left == DeleteNode ? x.Right = nullptr;
    // delete DeleteNode;

    assert(Root);

    std::queue<std::shared_ptr<Node<T>>> q;
    std::shared_ptr<Node<T>> Temp;

    q.push(Root);
    while (!q.empty())
    {
        Temp = q.front();
        q.pop();

        if (Temp->Left)
        {
            if (Temp->Left == NodePtr)
            {
                Temp->Left = nullptr;
                NodePtr.reset();
                return;
            }
            else
            {
                q.push(Temp->Left);
            }
        }

        if (Temp->Right)
        {
            if (Temp->Right == NodePtr)
            {
                Temp->Right = nullptr;
                NodePtr.reset();
                return;
            }
            else
            {
                q.push(Temp->Right);
            }
        }
    }
}

template <typename T>
void BinaryTree<T>::Print()
{
    assert(Root);
    LevelOrder(Root);
    std::cout << std::endl;
}

int main()
{
    BinaryTree<std::string> Tree;

    Tree.Insert("A");
    Tree.Insert("B");
    Tree.Insert("C");
    Tree.Insert("D");
    Tree.Insert("E");
    Tree.Insert("F");
    Tree.Insert("G");

    Tree.Print();

    Tree.Delete("B");

    Tree.Print();

    return 0;
}