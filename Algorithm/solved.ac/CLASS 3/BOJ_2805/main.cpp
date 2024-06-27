
#include <bits/stdc++.h>

constexpr int MAX = 1000001; // 1000001;
int n, m;

int t[MAX];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> t[i];
    }

    // 정렬하고 미드 짜른다음에
    // 내가 가져가야하는 길이가 m임. (7)

    std::sort(t, t + n);

    long long left = 0;
    long long right = t[n - 1];

    // 이분 탐색에서 left, right는 인덱스가 아닐수도 있고, 특정 값을 찾는게 아니라 다른 로직이 들어갈수도있다.
    // 그 조건에 따라 left, right값만 잘 증가,감소 시켜주면 될듯
    int max = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            if (t[i] <= mid)
            {
                continue;
            }

            sum += t[i] - mid;
        }

        if (sum >= m)
        {
            max = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << max;

    // int nn;
    // std::cin >> nn;
    return 0;
}