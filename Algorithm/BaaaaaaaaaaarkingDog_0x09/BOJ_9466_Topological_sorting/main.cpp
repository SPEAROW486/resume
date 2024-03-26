
#include <bits/stdc++.h>

constexpr int MAX = 100001;

int board[MAX];
int in_degree[MAX];

std::queue<int> q;
void Topology()
{
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        // 없는개수를 찾을수있는건가?

        int link = board[current];
        // 사이클이 있으면 이 조건을 통과할수가 없음.
        // 여기서는 진입 간선이 무조건 1개기 때문에 루프돌릴 필요가 없음.
        if (--in_degree[link] == 0)
        {
            q.push(link);
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

        int n;
        std::cin >> n;
        for (int i = 1; i < n + 1; ++i)
        {
            int team;
            std::cin >> team;
            board[i] = team;

            if (i != team)
            {
                ++in_degree[team];
            }
        }

        // q에 넣는다는건 사이클이 없다는것
        // 여기서는 진입 간선이 0이기 때문에 누구랑도 팀이 될 수 없는 애들임.
        for (int i = 1; i < n + 1; ++i)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        // 위상 정렬을 한번 돌고 나면
        // 3번에서 사이클이 발견되는데,
        // 나는 이제 4번부터 다시 사이클 체크를 해야한다고 생각했지만?
        // 안해도 되는 문제였음.
        // 왜 뒤에는 검증을 안해도 되는지에 대해서는 한번 생각해보아야함.
        Topology();
        int count = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (in_degree[i] == 0)
            {
                ++count;
            }
        }

        std::cout << count << "\n";
        std::fill(&in_degree[0], &in_degree[MAX], 0);
    }

    return 0;
}