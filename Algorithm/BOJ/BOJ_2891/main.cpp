
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, s, r;
std::vector<int> sv;
std::vector<int> rv;

int main()
{
    FASTIO;
    std::cin >> n >> s >> r;
    for (int i = 0; i < s; ++i)
    {
        int tmp;
        std::cin >> tmp;
        sv.push_back(tmp);
    }

    for (int i = 0; i < r; ++i)
    {
        int tmp;
        std::cin >> tmp;

        // 여분의 카약을 가져왔으나 기존 카약이 손상되었다면
        auto iter = std::find(sv.begin(), sv.end(), tmp);
        if (iter != sv.end())
        {
            sv.erase(iter);
            continue;
        }
        rv.push_back(tmp);
    }

    // 돌면서 sv에서 삭제하면딜듯?
    for (int i = 0; i < rv.size(); ++i)
    {
        const int &team = rv[i];
        {
            // 이전 팀
            auto iter = std::find(sv.begin(), sv.end(), team - 1);
            if (iter != sv.end())
            {
                sv.erase(iter);
                continue;
            }
        }
        {
            // 다음 팀
            auto iter = std::find(sv.begin(), sv.end(), team + 1);
            if (iter != sv.end())
            {
                sv.erase(iter);
                continue;
            }
        }
    }

    std::cout << sv.size() << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}