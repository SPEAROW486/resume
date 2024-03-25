
#include <bits/stdc++.h>

constexpr int MAX = 100001;
int board[MAX];
bool vis[MAX];

// 일단 쭉쭉 타고 들어가서 팀이 만들어진 애들은 싹 다 건너뛰게 했으니까 시간은 아까보다 줄였음.

// 1. 일단 vis를 int로 처리할수있다고함.
// -> 이러면 매번 초기화할 필요가 없음.
// 1.2 사이클을 추적해야함.
// 2. 정안되면 위상정렬 시작점과 끝점이 반드시 존재하는 비순환적 그래프 이기 때문에 이걸로 해결할수있다고함.

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;

    while (tc--)
    {
        int n;
        std::cin >> n;

        // INDEX 그냥 1부터 씀.
        // 링크 검사 할때 가리키고있는 숫자를 바로 인덱스로 쓰기위해서.
        for (int i = 1; i < n + 1; ++i)
        {
            int s;
            std::cin >> s;
            board[i] = s;
        }

        int match_count = 0;
        std::queue<std::tuple<int, int, int>> q;
        std::vector<int> buf;
        for (int i = 1; i < n + 1; ++i)
        {
            auto iter = std::find(buf.begin(), buf.end(), i);
            if (iter != buf.end())
            {
                // 이미 추적한 경로면
                continue;
            }

            if (i == board[i])
            {
                // 자기 자신을 가리키고 있으면
                ++match_count;
                buf.push_back(i);
                continue;
            }

            std::vector<int> v;
            q.push({i, i, board[i]});
            vis[i] = true;
            v.push_back(i);
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int entry, current, select;
                std::tie(entry, current, select) = cur;

                if (select == entry || select == current)
                {
                    buf.insert(buf.end(), v.begin(), v.end());
                    ++match_count;
                    break;
                }

                if (vis[select])
                {
                    continue;
                }

                vis[select] = true;
                q.push({entry, select, board[select]});
                v.push_back(select);
            }
            std::fill(&vis[0], &vis[MAX], false);
        }
        std::cout << n - match_count << "\n";
    }

    return 0;
}