

#include <iostream>
#include <vector>
#include <random>

class HeapMin
{
public:
    HeapMin() : v(HeapMin::MAX), heap_count(0) {}
    virtual ~HeapMin() = default;

    void Push(int Key);
    int Pop();

    bool isEmpty() const { return heap_count == 0; }

private:
    enum
    {
        MAX = 101
    };
    std::vector<int> v;
    int heap_count;
};

void HeapMin::Push(int Key)
{
    v[++heap_count] = Key;

    // make min heap
    int child = heap_count;
    int parent = child / 2;

    while (child > 1 && v[child] < v[parent])
    {
        std::swap(v[child], v[parent]);
        child = parent;
        parent = child / 2;
    }
}

int HeapMin::Pop()
{
    int ret = v[1];

    std::swap(v[1], v[heap_count]);
    v[heap_count] = 0; // 헷갈려서 걍 초기화 시켜버림
    heap_count--;

    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= heap_count)
    {
        // 자식 노드 중에 더 작은 값이랑 바꿔야하기 때문에 적절한 위치를 찾는다.
        child = v[child] < v[child + 1] ? child : child + 1;
    }

    while (child <= heap_count && v[child] < v[parent])
    {
        std::swap(v[parent], v[child]);
        parent = child;
        child = parent * 2;
        if (child + 1 <= heap_count)
        {
            child = v[child] < v[child + 1] ? child : child + 1;
        }
    }
    return ret;
}

int main()
{
    HeapMin h;
    std::vector<int> v;

    for (int i = 1; i < 101; ++i)
    {
        v.push_back(i);
    }

    std::shuffle(v.begin(), v.end(), std::default_random_engine());

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        h.Push(*it);
    }

    int count = 0;
    while (!h.isEmpty())
    {
        std::cout << h.Pop() << " ";

        if (++count % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}