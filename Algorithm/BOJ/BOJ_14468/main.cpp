
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

// 나타나는위치, 나가는 위치
std::vector<std::pair<int, int>> v;
int main()
{
    //    FASTIO;

    std::cin >> s;

    v.resize(26);
    for (int i = 0; i < 52; i++)
    {
        int idx = s[i] - 'A';
        if (v[idx].first == 0)
        {
            v[idx].first = i + 1;
        }
        else
        {
            v[idx].second = i + 1;
        }
    }

    int ans = 0;
    int n = 26;
    for (int i = 0; i < n; i++)
    {
        int s1 = v[i].first;
        int e1 = v[i].second;
        for (int j = 0; j < n; j++)
        {
            int s2 = v[j].first;
            int e2 = v[j].second;
            if (s1 < s2 && s2 < e1 && e1 < e2)
                ans++;
        }
    }
    std::cout << ans;

    int nn;
    std::cin >> nn;

    return 0;
}