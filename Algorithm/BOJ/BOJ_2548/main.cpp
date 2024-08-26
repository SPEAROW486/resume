
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    // 입력받은 숫자들을 정렬
    std::sort(v.begin(), v.end());

    // 1. N의 개수가 짝수인 경우
    //    중앙값이 2개이므로 더 작은 값 채택
    if (n % 2 == 0)
    {
        std::cout << v[n / 2 - 1];
    }
    // 2. N의 개수가 홀수인 경우
    //    중앙값이 1개이므로 바로 채택
    else
    {
        std::cout << v[n / 2];
    }

    // int nn;
    // std::cin >> nn;
    return 0;
}
