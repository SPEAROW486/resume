
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
std::vector<std::string> v;

int main()
{
    FASTIO;

    std::cin >> n >> k;

    std::string ans(n, '?');
    bool can = true;
    int pos = 0;

    for (int i = 0; i < k; ++i)
    {
        int tmp;
        char alphabet;
        std::cin >> tmp >> alphabet;

        // 위치 회전
        pos = (pos + tmp) % n;
        if (ans[pos] == '?')
        {
            ans[pos] = alphabet;
        }
        else if (ans[pos] != alphabet)
        {
            can = false;
            break;
        }
    }

    // 중복 알파벳
    std::set<char> used;
    for (auto ch : ans)
    {
        if (ch != '?')
        {
            if (used.find(ch) != used.end())
            {
                can = false;
                break;
            }
            used.insert(ch);
        }
    }

    if (can)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << ans[(pos + n - i) % n];
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "!\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}