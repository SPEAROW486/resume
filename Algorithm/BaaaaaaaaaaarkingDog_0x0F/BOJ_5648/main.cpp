
#include <bits/stdc++.h>

constexpr int MAX = 1000001;
long long buf[MAX];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        long long num;
        std::cin >> num;

        std::string s = std::to_string(num);
        std::reverse(s.begin(), s.end());

        num = std::stoll(s);
        buf[i] = num;
    }

    std::sort(buf, buf + n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << buf[i] << "\n";
    }

    // int nn;
    // std::cin >> n;
    return 0;
}