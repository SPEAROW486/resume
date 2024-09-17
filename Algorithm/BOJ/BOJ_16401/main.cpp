
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 16401
int m, n;
std::vector<long long> v;

bool can_distribution(long long mid)
{
    long long cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt += v[i] / mid;
    }
    return cnt >= m;
}

int main()
{
    FASTIO;
    std::cin >> m >> n;

    v.resize(n);

    long long longest = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        if (v[i] > longest)
        {
            longest = v[i];
        }
    }

    // 과자의 최소길이는 문제 조건상 1이고
    // 과자를 합칠수는없으니까 최대길이는 가장 긴 과자 길이?
    long long left = 1;
    long long right = longest;

    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (can_distribution(mid))
        {
            // 분배가 가능하다면 가능한 선에서 최대 길이를 찾아야하니까?
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