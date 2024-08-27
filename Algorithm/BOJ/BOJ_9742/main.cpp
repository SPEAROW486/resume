
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string solve(std::string s, int n)
{
    std::string result("No permutation");
    std::vector<std::string> v;
    int cnt = 0;
    do
    {
        std::string tmp;
        for (int i = 0; i < s.length(); ++i)
        {
            tmp += s[i];
        }
        ++cnt;
        if (cnt == n)
        {
            result = tmp;
        }
    } while (std::next_permutation(s.begin(), s.end()));

    return result;
}

int main()
{
    FASTIO;

    std::string s;
    int n;
    while (std::cin >> s >> n)
    {
        std::cout << s << " " << n << " = " << solve(s, n) << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}