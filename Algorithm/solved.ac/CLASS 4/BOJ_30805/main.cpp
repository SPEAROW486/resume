
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<std::pair<int, int>> a;
std::vector<std::pair<int, int>> b;

// 값 내림차순
bool cmp(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    if (lhs.second == rhs.second)
    {
        return lhs.first < rhs.first;
    }
    return lhs.second > rhs.second;
}

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        std::cin >> tmp;

        a.push_back({i, tmp});
    }

    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int tmp;
        std::cin >> tmp;

        b.push_back({i, tmp});
    }

    std::sort(a.begin(), a.end(), cmp);
    std::sort(b.begin(), b.end(), cmp);

    std::vector<int> s;
    int last_idx_i = -1;
    int last_idx_j = -1;

    // 풀이 참고함.
    // 처음에 lcs dp풀이로 해보다가 안되겠어서 태그 및 풀이 보니까 그리디였는데
    // 그리디 적인 풀이가 생각이 잘 안남.
    // 사전순으로 큰거를 하는거니까 큰 수를 택해야하고?
    // 규칙때문에 인덱스 조건을 추가해주는거였음.
    for (int i = 0; i < a.size(); ++i)
    {
        const int &value = a[i].second;
        for (int j = 0; j < b.size(); ++j)
        {
            if (b[j].second == value && last_idx_i < a[i].first && last_idx_j < b[j].first)
            {
                s.push_back(value);
                last_idx_i = a[i].first;
                last_idx_j = b[j].first;
            }
        }
    }

    std::cout << s.size() << "\n";
    for (int i = 0; i < s.size(); ++i)
    {
        std::cout << s[i] << " ";
    }
    return 0;
}