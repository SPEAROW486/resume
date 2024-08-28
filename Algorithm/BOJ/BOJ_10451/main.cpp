
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int tc;

bool is_cycle(int st, const std::vector<int> &edges, std::vector<bool> &visit)
{
    visit[st] = true;

    int tmp = st;
    while (true)
    {
        int en = edges[tmp];

        // 사이클이 반드시 존재하나?
        // 사이클이 없는 경우가 있다면 그건 어떻게 캐치해야하지?
        if (visit[en])
        {
            return true;
        }
        tmp = en;
        visit[en] = true;
    }

    return false;
}

int main()
{
    FASTIO;
    std::cin >> tc;

    while (tc--)
    {
        int n;
        std::cin >> n;

        std::vector<int> orders;
        std::vector<int> sequence;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            sequence.push_back(tmp);
            orders.push_back(i + 1);
        }

        // 간선 구성
        // i -> S[i]로 매핑
        std::vector<int> edges(n + 1);
        for (int i = 0; i < orders.size(); ++i)
        {
            edges[orders[i]] = (sequence[i]);
        }

        int ans = 0;
        std::vector<bool> visit(n + 1, false);
        for (int i = 0; i < orders.size(); ++i)
        {
            int st = orders[i];
            if (visit[st])
            {
                continue;
            }

            if (is_cycle(st, edges, visit))
            {
                ++ans;
            }
        }

        std::cout << ans << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}