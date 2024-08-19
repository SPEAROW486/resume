
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;
std::vector<std::string> v;

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

    // 행 검사
    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        std::string s = v[i];
        bool inDash = false;
        for (char ch : s)
        {
            if (ch == '-')
            {
                if (!inDash)
                {
                    count++;
                    inDash = true;
                }
            }
            else
            {
                inDash = false;
            }
        }
    }

    // 열 검사
    for (int i = 0; i < m; ++i)
    {
        bool inDash = false;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j][i] == '|')
            {
                if (!inDash)
                {
                    count++;
                    inDash = true;
                }
            }
            else
            {
                inDash = false;
            }
        }
    }

    std::cout << count;

    // int nn;
    // std::cin >> nn;
    return 0;
}