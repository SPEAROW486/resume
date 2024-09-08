#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int main()
{
    FASTIO;

    int n, x;
    // 배열의 크기 입력
    std::cin >> n >> x;

    std::vector<int> v(n);

    // 배열의 값 입력
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    // 최소값을 매우 큰 값으로 초기화
    long long min_value = 1e18;

    // 인접한 두 수의 곱 중 최소값 찾기
    for (int i = 0; i < n - 1; ++i)
    {
        min_value = std::min(min_value, 1LL * x * (v[i] + v[i + 1]));
    }

    // 결과 출력
    std::cout << min_value << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
