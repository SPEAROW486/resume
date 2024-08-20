#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int a, p;

std::unordered_map<int, int> map;

int solve(int n)
{
    int tmp = 0;
    std::stack<int> s;
    while (n > 0)
    {
        s.push(n % 10);
        n /= 10;
    }

    while (!s.empty())
    {
        tmp += pow(s.top(), p);
        s.pop();
    }

    return tmp;
}

int main()
{
    FASTIO;

    std::cin >> a >> p;
    while (true)
    {
        ++map[a];
        a = solve(a);

        if (map[a] > 1)
        {
            break;
        }
    }

    int ans = 0;
    for (auto it : map)
    {
        if (it.second == 1)
        {
            ++ans;
        }
    }

    std::cout << ans;

    // int nn;
    // std::cin >> nn;

    return 0;
}
