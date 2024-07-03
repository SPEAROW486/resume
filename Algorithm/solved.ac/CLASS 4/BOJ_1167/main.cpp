
#include <bits/stdc++.h>

constexpr int MAX = 100001;
int v;

std::vector<std::vector<std::pair<int, int>>> vec(MAX);
bool visit[MAX];

#define number first
#define dist second

int ans = 0;
int max_node = 0;

void dfs(int n, int sum)
{
    if (sum > ans)
    {
        ans = sum;
        max_node = n;
    }

    for (int i = 0; i < vec[n].size(); ++i)
    {
        const std::pair<int, int> &info = vec[n][i];
        if (visit[info.number])
        {
            continue;
        }

        visit[info.number] = true;
        dfs(info.number, sum + info.dist);
        visit[info.number] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> v;
    for (int i = 0; i < v; ++i)
    {
        int n;
        std::cin >> n;

        int an = 0, ad = 0;
        while (true)
        {
            std::cin >> an;
            if (an == -1)
            {
                break;
            }
            std::cin >> ad;
            vec[n].push_back({an, ad});
        }
    }

    // 트리의 지름을 구하는 공식임.
    // 임의의 정점 X를 잡고 가장 먼 정점 Y를 찾음.
    // 다시 Y에서부터 가장 먼 정점 Z를 찾으면 거기까지의 거리가 트리의 지름임
    visit[1] = true;
    dfs(1, 0);
    visit[1] = false;

    ans = 0;

    visit[max_node] = true;
    dfs(max_node, 0);
    visit[max_node] = false;

    std::cout << ans;

    // int nn;
    // std::cin >> nn;
    return 0;
}