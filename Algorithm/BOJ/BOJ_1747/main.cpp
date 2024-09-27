#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1747

// 소수 판별 함수
bool is_prime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// 팰린드롬 판별 함수
bool is_palindrome(int num)
{
    std::string str = std::to_string(num);
    int len = str.length();
    for (int i = 0; i < len / 2; ++i)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FASTIO;

    int n;
    std::cin >> n;

    // 입력 값보다 크거나 같은 소수이면서 팰린드롬인 수를 찾음
    for (int i = n;; ++i)
    {
        if (is_palindrome(i) && is_prime(i))
        {
            std::cout << i << '\n';
            break;
        }
    }

    return 0;
}
