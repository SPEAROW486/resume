#include <iostream>
#include <string>

namespace Editor
{
    class List;
    class Iterator;

    struct Node
    {
        friend class List;
        friend class Iterator;

    private:
        Node() : data('\0'), prev(nullptr), next(nullptr) {}
        Node(const char c) : data(c), prev(nullptr), next(nullptr)
        {
        }

        ~Node()
        {
            std::cout << "Call Destructor : " << data << std::endl;
        }

        char data;
        Node *prev;
        Node *next;
    };

    class Iterator
    {
        friend class List;

    private:
        Iterator() = delete;
        Iterator(Node *node) : ptr(node)
        {
        }
        Node *ptr;

    public:
        Iterator &operator++()
        {
            ptr = ptr->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++*this;
            return temp;
        }

        Iterator &operator--()
        {
            ptr = ptr->prev;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            --*this;
            return temp;
        }

        bool operator==(const Iterator &other)
        {
            return this->ptr == other.ptr;
        }

        bool operator!=(const Iterator &other)
        {
            return this->ptr != other.ptr;
        }

        char operator*()
        {
            return ptr->data;
        }
    };

    class List
    {
    public:
        List() = default;
        List(const std::string &str);
        ~List();

        void Push_Back(const char c);
        void Insert(Iterator iter, const char c);
        Editor::Iterator Erase(Iterator iter);
        void Print();

        Editor::Iterator Begin();
        Editor::Iterator End();

    private:
        Node *end;
    };

    List::List(const std::string &str)
    {
        end = new Node();
        end->prev = end;
        end->next = end;

        for (const auto &elem : str)
        {
            Push_Back(elem);
        }
    }

    List::~List()
    {
        Editor::Iterator iter = Begin();
        while (iter != End())
        {
            Node *temp = iter.ptr;
            ++iter;
            delete temp;
        }
        delete iter.ptr;
    }

    void List::Push_Back(const char c)
    {
        Node *node = new Node(c);

        node->next = end;
        node->prev = end->prev;
        node->prev->next = node;
        end->prev = node;
    }

    void List::Insert(Iterator iter, const char c)
    {
        // iter에 좌측에
        Node *node = new Node(c);
        node->next = iter.ptr;

        Node *prev_node = iter.ptr->prev;
        node->prev = prev_node;

        prev_node->next = node;

        iter.ptr->prev = node;
    }

    Editor::Iterator List::Erase(Iterator iter)
    {
        // 지우려고 하는 iter->next를 리턴해줘야함
        Node *prev_node = iter.ptr->prev;
        prev_node->next = iter.ptr->next;

        iter.ptr->next->prev = prev_node;

        Editor::Iterator ret = (iter.ptr->next);

        delete iter.ptr;
        iter.ptr = nullptr;
        return ret;
    }

    void List::Print()
    {
        Editor::Iterator iter = Begin();
        while (iter != End())
        {
            std::cout << *iter;
            ++iter;
        }
        std::cout << std::endl;
    }

    Editor::Iterator List::Begin()
    {
        return Editor::Iterator(end->next);
    }
    Editor::Iterator List::End()
    {
        return Editor::Iterator(end);
    }
}

int main()
{
    std::string s("ABC");
    Editor::List list(s);

    // ABCD
    auto iter = list.End();
    list.Insert(iter, 'D');
    list.Print();

    // BCD
    auto iter2 = list.Begin();
    list.Erase(iter2);
    list.Print();
    return 0;
}
