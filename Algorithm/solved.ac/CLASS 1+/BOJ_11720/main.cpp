#include <bits/stdc++.h>

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int n;
    std::string s;

    std::cin >> n;
    std::cin >> s;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += s[i] - '0';
    }

    std::cout << sum;
    return 0;
}