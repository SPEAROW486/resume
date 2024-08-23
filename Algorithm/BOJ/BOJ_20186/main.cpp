
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

int n, k;
std::vector<int> v;

int main()
{
    // FASTIO;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    int accum = std::accumulate(v.end() - k, v.end(), 0);
    std::cout << accum - (k * (k - 1) / 2);

    // 1개를 고르면 차감되는 점수 0점
    // 2개를 고르면 차감되는 점수 1점
    // k개를 고르면 k-1점이 깎이니까
    // 1~K개까지 골랐을때 차감되는 점수의 합은 0 + 1 + K - 1이므로
    // k * (k-1) /2임.

    int nn;
    std::cin >> nn;
    return 0;
}