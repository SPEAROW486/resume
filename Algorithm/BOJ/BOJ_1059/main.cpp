
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int l, n;
std::vector<int> s;

int main()
{
    FASTIO;

    std::cin >> l;
    for (int i = 0; i < l; ++i)
    {
        int tmp;
        std::cin >> tmp;
        s.push_back(tmp);
    }
    s.push_back(0);

    std::cin >> n;
    int st, en;
    bool ans = true;
    std::sort(s.begin(), s.end());
    for (int i = 1; i < l + 1; i++)
    {
        if (n == s[i])
        {
            ans = false;
        }
        else if (n < s[i])
        {
            st = s[i - 1] + 1;
            en = s[i] - 1;
            break;
        }
    }

    if (ans)
        std::cout << (n - st) * (en - n + 1) + (en - n);
    else
        std::cout << 0;

    // int nn;
    // std::cin >> nn;
    return 0;
}