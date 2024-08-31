#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 24511
// 1. 큐/스택을 동시에 하는거니까 덱으로?

int n, m;
std::deque<int> dq;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;

    std::vector<int> types(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> types[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        if (types[i] == 0)
        {
            dq.push_back(tmp);
        }
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        std::cin >> tmp;

        dq.push_front(tmp);
        std::cout << dq.back() << " ";
        dq.pop_back();
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
