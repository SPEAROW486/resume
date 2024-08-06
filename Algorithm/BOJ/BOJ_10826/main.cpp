
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// 두 개의 큰 숫자를 더하는 함수
std::vector<int> addBigNumbers(const std::vector<int> &a, const std::vector<int> &b)
{
    std::vector<int> result;
    int carry = 0;
    size_t maxLength = std::max(a.size(), b.size());

    for (size_t i = 0; i < maxLength || carry; ++i)
    {
        int digitA = (i < a.size()) ? a[i] : 0;
        int digitB = (i < b.size()) ? b[i] : 0;
        int sum = digitA + digitB + carry;

        result.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}

// 피보나치 수열을 구하는 함수
std::vector<int> fibonacci(int n)
{
    if (n == 0)
        return {0};
    if (n == 1)
        return {1};

    std::vector<int> a = {0};
    std::vector<int> b = {1};

    for (int i = 2; i <= n; ++i)
    {
        std::vector<int> next = addBigNumbers(a, b);
        a = b;
        b = next;
    }

    return b;
}

// 큰 숫자를 출력하는 함수
void printBigNumber(const std::vector<int> &num)
{
    for (auto it = num.rbegin(); it != num.rend(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> result = fibonacci(n);
    printBigNumber(result);

    return 0;
}
