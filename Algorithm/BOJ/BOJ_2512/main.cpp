#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2512
// 이분 탐색

int n, m;
std::vector<int> v;

int main()
{
    FASTIO;
    std::cin >> n;
    v.resize(n);

    int sum = 0;
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        sum += v[i];
        max = std::max(max, v[i]);
    }
    std::cin >> m;

    if (m >= sum)
    {
        std::cout << max << "\n";
    }
    else
    {
        int left = 1;
        int right = 1e9;

        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            // mid값이 상한액이라고 하면
            // 이 상한액보다 값이 큰 애들은 미드 값으로 치환해서 처리하고 그 핪이 m보다 작거나 같을때의 mid값이 정답

            sum = 0;
            for (int i = 0; i < n; ++i)
            {
                int tmp = v[i] < mid ? v[i] : mid;
                sum += tmp;
            }

            if (sum <= m)
            {
                ans = std::max(ans, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        std::cout << ans << "\n";
    }

    // int nn;
    // std::cin >> nn;

    return 0;
}
