
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<std::vector<int>> vec;

void solution()
{
    int tmp = 0;
    int ans = 1; // 전부 한번도 친구였던적이 없다면 -> 어쨌든 0명으로 동일한거니까 1번 친구가 임시반장이 되어야해서
    for (int i = 1; i <= n; ++i)
    {
        std::unordered_set<int> s;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                continue;
            }

            for (int k = 0; k < 5; ++k)
            {
                // i번째 학생의 k학년때 반과 같다면
                if (vec[i][k] == vec[j][k])
                {
                    s.insert(j);
                }
            }
        }

        if (s.size() > tmp)
        {
            ans = i;
            tmp = s.size();
        }
    }

    std::cout << ans;
}

int main()
{
    FASTIO;
    std::cin >> n;
    vec.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int class_number;
            std::cin >> class_number;
            vec[i].push_back(class_number);
        }
    }

    solution();

    // int nn;
    // std::cin >> nn;
    return 0;
}