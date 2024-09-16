#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 15810

// 풍선을 만들 수 있는지 확인하는 함수
bool canMakeBalloons(long long time, std::vector<int> &times, long long m)
{
    long long totalBalloons = 0;
    for (int t : times)
    {
        totalBalloons += time / t;
        if (totalBalloons >= m)
        {
            return true;
        }
    }
    return totalBalloons >= m;
}

int main()
{
    FASTIO;

    // 입력 받기
    int n;       // 직원 수
    long long m; // 만들어야 하는 풍선의 수
    std::cin >> n >> m;

    std::vector<int> times(n); // 각 직원이 풍선을 만드는 데 걸리는 시간
    for (int i = 0; i < n; ++i)
    {
        std::cin >> times[i];
    }

    // 이분 탐색 범위 설정
    long long left = 1;                                                  // 최소 시간
    long long right = *std::min_element(times.begin(), times.end()) * m; // 최대 시간

    // 이분 탐색 시작
    long long result = right;
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        // mid 시간 안에 풍선을 만들 수 있는지 확인
        if (canMakeBalloons(mid, times, m))
        {
            result = mid;
            right = mid - 1; // 더 짧은 시간도 가능한지 확인
        }
        else
        {
            left = mid + 1; // 시간을 늘려야 함
        }
    }

    // 결과 출력
    std::cout << result << '\n';

    // int nn;
    // std::cin >> nn;

    return 0;
}
