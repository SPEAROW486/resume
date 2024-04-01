
#include <bits/stdc++.h>

// review 2024-04-01 -----> 솔직히 BFS로 풀 문제가 아닌거 같은 생각도..? 애초에 대부분 DFS로 푸는 듯
// 이 문제에서는 방문할때 노드의 방문 여부를 노드 번호로 덮어씌운다.
// 방문하지 않았으면 0이고, 방문을 했으면 노드 번호가 있는데, 방문 처리를 하고, 방문 플래그가 현재 탐색하고있는 노드랑 같다면 경로를 찾은거임.

// 키 포인트는 2가지 같음.
// 1. 방문 배열을 int 배열로 놓고, 특정한 식별자로 덮어 씌워가면서 체크한다.
// 2. 방문 과정에서 순환 구조인지 찾는다.

constexpr int MAX = 100001;
int board[MAX];
int vis[MAX];

constexpr int NOT_VISITED = 0;
constexpr int IN_CYCLE = -1;

int n;
void Cycle(int i)
{
    // i가 1일때
    // 1번노드방문시 1번
    int cur = i;
    while (true)
    {
        vis[cur] = i;
        cur = board[cur];
        if (vis[cur] == i)
        {
            while (vis[cur] != IN_CYCLE)
            {
                vis[cur] = IN_CYCLE;
                cur = board[cur];
            }
            return;
        }
        else if (vis[cur] != NOT_VISITED)
        {
            // 방문을 했는데 다른 노드면 사이클이 없는거
            return;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> board[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            if (vis[i] != NOT_VISITED)
            {
                continue;
            }
            Cycle(i);
        }

        int count = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i] != IN_CYCLE)
            {
                ++count;
            }
        }

        std::cout << count << "\n";
        std::fill(&vis[0], &vis[MAX], 0);
    }

    return 0;
}