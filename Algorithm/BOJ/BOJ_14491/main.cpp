#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14491

int main()
{
    FASTIO;

    int n;
    std::cin >> n;

    std::vector<int> result;

    // 9진수로 변환하여 result 벡터에 저장
    while (n > 0)
    {
        result.push_back(n % 9);
        n /= 9;
    }

    // 역순으로 출력하여 9진수 표현
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        std::cout << *it;
    }

    std::cout << "\n";

    return 0;
}
