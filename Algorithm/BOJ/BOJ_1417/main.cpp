
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 51;
int n;

int board[MAX];

int main()
{
    FASTIO;
    std::cin >> n;

    std::priority_queue<int> pq;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> board[i];

        if (i != 1)
        {
            pq.push(board[i]);
        }
    }

    // 5 7 7 이렇게 입력이 들어와있음.
    // 다솜이는 무조건 1번
    int ans = 0;

    while (!pq.empty() && board[1] <= pq.top())
    {
        const int top = pq.top();
        pq.pop();

        pq.push(top - 1);
        ++board[1];
        ++ans;
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}