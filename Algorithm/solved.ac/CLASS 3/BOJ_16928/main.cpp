
#include <bits/stdc++.h>

constexpr int MAX = 101; // 501;

int board[MAX];
int visit[MAX];
int n, m;

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n + m; ++i)
    {
        int st, en;
        std::cin >> st >> en;

        board[st] = en;
    }

    std::fill(visit, visit + MAX, -1);

    std::queue<int> q;
    q.push(1);
    visit[1] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (front == 100)
        {
            std::cout << visit[front];
            return 0;
        }

        for (int i = 1; i <= 6; ++i)
        {
            int nx = front + i;
            if (nx > 100)
            {
                continue;
            }

            // 12->86으로 가는 사다리나 12->3으로 가는 스네이크가 있다면
            if (board[nx] != 0)
            {
                visit[nx] = visit[front] + 1;
                nx = board[nx];
            }

            // 사다리나 뱀을 타고 도착지가 바뀔 수 있으니 그거까지 처리한 후에 방문여부 검사를 해야함.
            // 이거 놓쳐가지고 30분 헤맴..
            if (visit[nx] != -1)
            {
                continue;
            }

            visit[nx] = visit[front] + 1;
            q.push(nx);
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}