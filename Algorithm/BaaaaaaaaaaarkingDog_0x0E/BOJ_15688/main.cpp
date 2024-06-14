
#include <bits/stdc++.h>

// constexpr int MAX = 1000001;
// int buf[MAX];
int n;

std::map<int, int> m;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;
        m[number]++;
    }

    for (const auto &elem : m)
    {
        int number = elem.first;
        int count = elem.second;
        for (int j = 0; j < count; ++j)
        {
            std::cout << number << "\n";
        }
    }

    // std::cin >> n;
    return 0;
}