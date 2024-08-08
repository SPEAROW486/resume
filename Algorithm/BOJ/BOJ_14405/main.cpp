
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)
std::string s;
bool ans;

void func(int idx)
{
    if (idx == s.length())
    {
        ans = true;
        return;
    }

    if (s.substr(idx, 2) == "pi" || s.substr(idx, 2) == "ka")
    {
        func(idx + 2);
    }

    if (s.substr(idx, 3) == "chu")
    {
        func(idx + 3);
    }
}

int main()
{
    FASTIO;

    std::cin >> s;

    func(0);
    std::cout << (ans ? "YES\n" : "NO\n");

    // int nn;
    // std::cin >> nn;
    return 0;
}