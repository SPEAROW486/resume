#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 20301
// 그냥 구현?

int n, k, m;
std::deque<int> dq;

void solve()
{
    bool right = true;
    int cnt = 0;
    while (!dq.empty())
    {
        if (right)
        {
            for (int i = 0; i < k - 1; ++i)
            {
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }
            std::cout << dq.front() << "\n";
            dq.pop_front();
        }
        else
        {
            for (int i = 0; i < k - 1; ++i)
            {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
            }
            std::cout << dq.back() << "\n";
            dq.pop_back();
        }

        ++cnt;
        if (cnt == m)
        {
            right = !right;
            cnt = 0;
        }
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> k >> m;

    for (int i = 0; i < n; ++i)
    {
        dq.push_back(i + 1);
    }

    solve();

    // int nn;
    // std::cin >> nn;
    return 0;
}
