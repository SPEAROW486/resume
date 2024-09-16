#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 14627
// 매개변수 탐색

int s, c;

std::vector<int> v;

long long divide(int m)
{
    long long sum = 0;
    for (int i = 0; i < s; ++i)
    {
        sum += v[i] / m;
    }
    return sum;
}

int main()
{
    FASTIO;
    std::cin >> s >> c;

    v.resize(s);
    long long total_length = 0; // 전체 파의 길이를 저장
    for (int i = 0; i < s; ++i)
    {
        std::cin >> v[i];
        total_length += v[i]; // 전체 파 길이 계산
    }

    long long left = 1;
    long long right = 1e9;
    long long best_len = 0; // 조건을 만족하는 최대 길이
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long cnt = divide(mid);
        if (cnt >= c)
        {
            best_len = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    long long ans = total_length - best_len * c;
    std::cout << ans << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
