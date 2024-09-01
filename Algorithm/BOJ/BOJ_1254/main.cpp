#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1254
// 기존 문자열에서 sub[0..i-1] 문자열을 만들어서 뒤집은다음에 뒤에 붙혀보고 체크?

std::string s;

bool check(std::string str)
{
    int left = 0;
    int right = str.length() - 1;

    for (int i = 0; i < str.length() / 2; ++i)
    {
        if (str[i] != str[right - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FASTIO;
    std::cin >> s;

    // 입력 자체가 팰린드롬일 경우
    if (check(s))
    {
        std::cout << s.length() << "\n";
    }
    else
    {
        for (int i = 1; i < s.length(); ++i)
        {
            std::string sub = s.substr(0, i);
            std::reverse(sub.begin(), sub.end());

            std::string tmp = s + sub;

            if (check(tmp))
            {
                std::cout << tmp.length() << "\n";
                break;
            }
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
