
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;

int main()
{
    FASTIO;
    std::cin >> n;

    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    std::vector<int> v;
    while (q.size() != 1)
    {
        // 한장을 버린다.
        const int discard = q.front();
        v.push_back(discard);
        q.pop();

        const int card_move_down = q.front();
        q.pop();
        q.push(card_move_down);
    }

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }

    std::cout << q.front();

    // int nn;
    // std::cin >> nn;
    return 0;
}