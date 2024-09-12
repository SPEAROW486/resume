
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 13702
// 이분 탐색

int n, k;
std::vector<long long> v;

int distribution(long long ml)
{
    // 이제 여기서 분배가능한 최대 인원수를 찾아야함.
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret += v[i] / ml;
    }

    return ret;
}

int main()
{
    FASTIO;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    long long left = 1;
    long long right = *max_element(v.begin(), v.end()); // 주전자 중 가장 큰 값

    // 어떤 비교값이 있어야 mid가지고 연산한 결과랑 비교할듯
    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int dist = distribution(mid);

        if (dist >= k)
        {
            // K <= dist 조건 하나 때문에 빙빙 돌았네..
            // 이 조건을 충족하는 가장 큰 값을 찾아나가는거니까 left를 증가시키는게 맞는거같은데
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}