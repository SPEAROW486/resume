
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 1793
// DP

constexpr int MAX = 251;
std::string dp[MAX]; // dp[i] = 2*i 사이즈의 타일을 가로,세로 방식으로 채우는 방법, 가로랑 정사각형은 구분하지 않음.

std::string addBigInt(const std::string &a, const std::string &b)
{
    std::string result = "";
    int carry = 0, sum = 0;
    int lenA = a.size(), lenB = b.size();
    int len = std::max(lenA, lenB);

    for (int i = 0; i < len; i++)
    {
        int digitA = i < lenA ? a[lenA - 1 - i] - '0' : 0;
        int digitB = i < lenB ? b[lenB - 1 - i] - '0' : 0;

        sum = digitA + digitB + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry)
    {
        result += carry + '0';
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string multiplyBigInt(const std::string &a, int b)
{
    std::string result = "";
    int carry = 0, product = 0;
    int lenA = a.size();

    for (int i = 0; i < lenA; i++)
    {
        int digitA = a[lenA - 1 - i] - '0';
        product = digitA * b + carry;
        carry = product / 10;
        result += (product % 10) + '0';
    }

    while (carry)
    {
        result += (carry % 10) + '0';
        carry /= 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FASTIO;

    dp[0] = "1"; // nC0이 1인건 알겠는데 이 문제에서는 타일로 채우는 방법이니까 안채우는건 고려안해도되는거아닌가..?

    dp[1] = "1"; // 2*1 세로 타일로 한개 채울 수 있음
    dp[2] = "3";
    // 좌상단부터 가로타일, 세로타일로 채우는 경우랑 정사각형 타일로 채우는 경우가 있음.

    for (int i = 3; i < MAX; ++i)
    {
        dp[i] = addBigInt(dp[i - 1], multiplyBigInt(dp[i - 2], 2));
    }

    int n;
    while (std::cin >> n)
    {
        std::cout << dp[n] << "\n";
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}