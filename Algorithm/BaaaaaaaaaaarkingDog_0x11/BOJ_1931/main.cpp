
#include <bits/stdc++.h>

int n;
std::vector<std::pair<int, int>> v;

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    // 명제 : 빨리 끝나는 회의들중에서 가장 먼저 시작하는거부터 회의를 시작하면됨.
    // 이 명제가 참이라고 가정하면 모순이 있는지를 찾아야하는데

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        std::cin >> start >> end;

        v.push_back({end, start});
    }

    std::sort(v.begin(), v.end());

    int finish = 0;
    int count = 0;
    for (const auto &elem : v)
    {
        int start, end;
        std::tie(end, start) = elem;

        if (start >= finish)
        {
            finish = end;
            ++count;
        }
    }

    std::cout << count;

    return 0;
}