
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int m, n;
std::string numbers[10] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine"};

std::string solve(int n)
{
    std::stack<int> stack;
    while (n > 0)
    {
        stack.push(n % 10);
        n /= 10;
    }

    std::string ret;
    while (!stack.empty())
    {
        ret += numbers[stack.top()];
        stack.pop();
    }
    return ret;
}

int main()
{
    FASTIO;

    std::cin >> m >> n;

    std::map<std::string, int> map;
    for (int i = m; i <= n; ++i)
    {
        std::string s = solve(i);
        map[s] = i;
    }

    int cnt = 0;
    for (auto pair : map)
    {
        ++cnt;
        std::cout << pair.second << " ";
        if (cnt % 10 == 0)
        {
            std::cout << "\n";
        }
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}