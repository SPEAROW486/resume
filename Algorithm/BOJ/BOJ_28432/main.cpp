
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, m;

std::vector<std::string> s;
std::vector<std::string> a;

int main()
{
    FASTIO;

    std::cin >> n;

    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        s.push_back(tmp);

        if (tmp == "?")
        {
            idx = i;
        }
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < m; ++i)
    {
        // 중복 검사
        if (std::find(s.begin(), s.end(), a[i]) != s.end())
        {
            continue;
        }
        bool can = true;
        // 중복이 아니면
        if ((idx == 0 || idx == n - 1) && s.size() > 1)
        {
            // 양 끝단
            if (idx == 0)
            {
                std::string backward = s[idx + 1];
                can = backward.front() == a[i].back();
            }
            else
            {
                std::string forward = s[idx - 1];
                can = forward.back() == a[i].front();
            }
        }
        else
        {
            // 사이
            if (s.size() > 2)
            {
                std::string forward = s[idx - 1];
                std::string backward = s[idx + 1];
                can = forward.back() == a[i].front() && backward.front() == a[i].back();
            }
        }

        if (can)
        {
            std::cout << a[i] << "\n";
            break;
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}