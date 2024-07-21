
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;
    std::string s;
    std::cin >> s;

    if (s.find('X') == std::string::npos)
    {
        // ..........만 있으면 .......... 그대로 출력해야된다는걸 문제 읽고 어떻게알아;
        std::cout << s;
        return 0;
    }

    std::string ans;
    int cnt = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '.')
        {
            ans += '.';
            // .을 만났는데 여태 까지 쌓은 카운트가 홀수면 아무것도못하는거아님?
            if (cnt % 2 != 0)
            {
                std::cout << -1;
                return 0;
            }
            else
            {
                cnt = 0;
            }
            continue;
        }

        if (s[i] == 'X')
        {
            ++cnt;
        }

        if (cnt == 4)
        {
            ans += "AAAA";
            cnt = 0;
        }
        else if (cnt == 2 && s[i + 1] != 'X')
        {
            ans += "BB";
            cnt = 0;
        }
    }

    if (cnt % 2 == 1)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans;
    }
    // int nn;
    // std::cin >> nn;
    return 0;
}