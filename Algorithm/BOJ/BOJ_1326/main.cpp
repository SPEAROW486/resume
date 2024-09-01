
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1326
// 1차원 BFS로 접근할 수 있을듯
// 이동 방향만 배수 처리 해주면 될듯한데

constexpr int MAX = 10001;
int n;
int a, b;
std::vector<int> v;

int visit[MAX];

std::vector<int> get_multiples_less_n(int number)
{
    std::vector<int> multiples;

    int bias = 1;
    for (int i = number; i < n;)
    {
        multiples.push_back(i);
        i = number * ++bias;
    }

    return multiples;
}

int main()
{
    FASTIO;

    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    // 입력은 1-based
    std::cin >> a >> b;
    std::fill(visit, visit + MAX, -1);

    std::queue<int> q;
    q.push(a - 1);
    visit[a - 1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 현재 위치에서 이동할 수 있는 모든 위치를 계산
        for (int i = 1;; ++i)
        {
            int next_right = cur + i * v[cur];
            int next_left = cur - i * v[cur];

            // 오른쪽으로 점프
            if (next_right < n && visit[next_right] == -1)
            {
                q.push(next_right);
                visit[next_right] = visit[cur] + 1;
            }

            // 왼쪽으로 점프
            if (next_left >= 0 && visit[next_left] == -1)
            {
                q.push(next_left);
                visit[next_left] = visit[cur] + 1;
            }

            // 현재 계산한 위치가 범위를 벗어나면 더 이상 진행하지 않음
            if (next_right >= n && next_left < 0)
            {
                break;
            }
        }
    }

    std::cout << visit[b - 1] << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}