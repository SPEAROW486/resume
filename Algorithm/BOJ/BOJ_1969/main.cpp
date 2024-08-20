
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<std::string> v;

int get_distance(std::string s1, std::string s2)
{
    int dist = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        if (s1[i] != s2[i])
        {
            ++dist;
        }
    }

    return dist;
}

int main()
{
    FASTIO;

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::string ans;
    ans.resize(m);
    for (int i = 0; i < m; ++i)
    {
        std::map<char, int> map;
        for (int j = 0; j < v.size(); ++j)
        {
            ++map[v[j][i]];
        }

        char atgc;
        int max = INT_MIN;
        for (auto it : map)
        {
            if (it.second > max)
            {
                max = it.second;
                atgc = it.first;
            }
        }

        ans[i] = atgc;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        sum += get_distance(ans, v[i]);
    }

    std::cout << ans << "\n";
    std::cout << sum;

    // int nn;
    // std::cin >> nn;
    return 0;
}