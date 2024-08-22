
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

std::string s;

std::string solve()
{
    // 30의 배수가 되려면
    // 0으로 끝나야하고, 각 자리수의 합이 3의 배수여야함.
    std::sort(s.begin(), s.end(), std::greater<>());
    if (s.back() != '0')
    {
        return "-1";
    }

    int sum_of_digit = 0;
    for (char ch : s)
    {
        int digit = ch - '0';
        sum_of_digit += digit;
    }

    if (sum_of_digit % 3 != 0)
    {
        return "-1";
    }

    return s;
}

int main()
{
    FASTIO;

    std::cin >> s;
    std::cout << solve();

    // int nn;
    // std::cin >> nn;
    return 0;
}