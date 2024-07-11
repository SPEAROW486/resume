
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 51; // 51;
constexpr int HOUSE = 1;
constexpr int STORE = 2;

int n, m;
std::vector<std::pair<int, int>> stores;
std::vector<std::pair<int, int>> house_list;
bool visit[MAX];

int ans = INT_MAX;

void backtrack(int idx, int count)
{
    if (count == m)
    {
        // 거리 구하기
        // 하우스에서 치킨 집들 까지
        int sum = 0;
        for (int j = 0; j < house_list.size(); ++j)
        {
            int hr = house_list[j].first;
            int hc = house_list[j].second;
            int dist = INT_MAX;
            for (int i = 0; i < stores.size(); ++i)
            {
                if (!visit[i])
                {
                    continue;
                }

                int sr = stores[i].first;
                int sc = stores[i].second;

                dist = std::min(dist, abs(hr - sr) + abs(hc - sc));
            }
            sum += dist;
        }
        ans = std::min(ans, sum);
        return;
    }

    // 조합까진 생각했고 그걸 백트래킹으로 코드를 옮기려는데
    // 여태 풀었던게 2차원 그래프에서의 백트래킹이라 1차원일때 어떻게 할지? 생각이 안났음.
    // next_permutation이던 백트래킹이던 불값을 놓고 사용 유무를 체크해서 조합을 고를 수 있음..?
    for (int i = idx; i < stores.size(); ++i)
    {
        if (visit[i])
        {
            continue;
        }

        // i번째 가게를 폐업시키지 않을거임
        visit[i] = true;
        backtrack(i + 1, count + 1);
        visit[i] = false;
    }
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int v;
            std::cin >> v;

            if (v == STORE)
            {
                stores.push_back({i, j});
            }

            if (v == HOUSE)
            {
                house_list.push_back({i, j});
            }
        }
    }

    backtrack(0, 0);

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}