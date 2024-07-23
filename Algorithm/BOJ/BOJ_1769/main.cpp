
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string n;

void solve(std::string x)
{
    int cnt = 0;
    // 계속 변환
    while (x.length() > 1)
    {
        int sum = 0;
        for (int i = 0; i < x.length(); ++i)
        {
            sum += x[i] - '0';
        }
        x = std::to_string(sum);
        ++cnt;
    }
    const std::string result = std::stoi(x) % 3 == 0 ? "YES" : "NO";

    std::cout << cnt << "\n";
    std::cout << result;
}

int main()
{
    FASTIO;
    std::cin >> n;

    solve(n);
    return 0;
}