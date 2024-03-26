
#include <bits/stdc++.h>

constexpr int MAX = 100001;
int board[MAX];
int state[MAX];

constexpr int NOT_VISITED = 0;
constexpr int CYCLE_IN = -1;

// memo 2024-03-25
// 솔직히 제대로 푼거 같지가 않음.
// 방문 확인용 버퍼를 bool 이나 dist 용도로 활용해서 ++ 해가는거는 익숙해졌는데
// 어떤 플래그 값으로 덮어씌워서 활용하는거는 다른 문제를 더 풀어봐야 할 거 같음.
// 이 문제에서는 방문할때 노드의 방문 여부를 노드 번호로 덮어씌운다.
// 방문하지 않았으면 0이고, 방문을 했으면 노드 번호가 있는데, 방문 처리를 하고, 방문 플래그가 현재 탐색하고있는 노드랑 같다면 사이클을 찾은거임.

// 키 포인트는 2가지 같음.
// 1. 방문 배열을 int 배열로 놓고, 특정한 식별자로 덮어 씌워가면서 체크한다.
// 2. 방문 과정에서 순환 구조인지 찾는다.

void Cycle(int idx)
{
    // 노드번호로 덮어씌우면서 간다고치면?
    int cur = idx;
    while (true)
    {
        // 여기가 방문처리
        // cur는 계속 간선으로 갱신됨.
        // 근데 state[cur] = idx로 계속 덮어 씌우니까
        // 경로를 끝까지 탐색하고나면 결국 state[cur] == idx랑 같아짐.
        state[cur] = idx;
        cur = board[cur];

        // 이번 탐색에서 경로를 끝까지 돌았다면 2번째로 방문하는 지점이 생김.
        // 그게 cur임.

        // 1->2->3->4->5->4 라면
        // 방문 플래그는 전부 1,1,1,1,1로 찍혀있고
        // cur만 다시 4로 돌아오기 때문에
        // state[4]는 이미 idx 세팅되어있기 때문에
        // 같다라는거임.
        // 방문을 안했으면 낫 비지티드고
        // 방문을 했으면 노드 번호가 있는데
        // 탐색을 시작한 노드번호랑 같다라는건 싸이클을 찾은것.
        if (state[cur] == idx)
        {
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN;
                cur = board[cur];
            }
            return;
        }
        // 경로를 탐색을 하는데 방문한적이 있다면 그쪽은 이미 싸이클 탐색이 끝났으므로 아무것도 할 필요가 없다.
        else if (state[cur] != NOT_VISITED)
        {
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

    // 방문 확인용 배열을 매번 초기화하면 N^2이 되니까
    // 매번 초기화 하지 않고 새로운 값으로 덮어씌우는 테크닉을 활용해야함.
    // 여기선 노드 번호를 덮어씌우면서 지나갈거임.
    while (tc--)
    {
        int n;
        std::cin >> n;
        std::fill(state + 1, state + n + 1, NOT_VISITED);
        for (int i = 1; i < n + 1; ++i)
        {
            std::cin >> board[i];
        }

        for (int i = 1; i < n + 1; ++i)
        {
            if (state[i] == NOT_VISITED)
            {
                Cycle(i);
            }
        }

        int cnt = 0;
        for (int i = 1; i < n + 1; ++i)
        {
            if (state[i] != CYCLE_IN)
            {
                ++cnt;
            }
        }
        std::cout << cnt << "\n";
    }
    return 0;
}