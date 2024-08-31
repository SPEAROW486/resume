#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 20300
// 그리디..?
// 홀수면 가장 큰 값만 단독으로 채택하고 나머지중에서 작은값 큰값 매칭
// 짝수면 그냥 매칭

int n;
std::vector<long long> v;

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        long long tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    long long max = 0;
    if (n % 2 != 0)
    {
        max = v.back();
        v.pop_back();
        --n;
    }

    for (int i = 0; i < n / 2; ++i)
    {
        long long tmp = v[i] + v[n - i - 1];
        max = std::max(max, tmp);
    }

    std::cout << max;

    // int nn;
    // std::cin >> nn;
    return 0;
}
