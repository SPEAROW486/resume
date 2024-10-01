#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2792

int main()
{
    FASTIO;

    int n, m; // 학생 수와 보석의 종류 수
    std::cin >> n >> m;

    std::vector<int> jewels(m);
    int maxJewels = 0;

    for (int i = 0; i < m; ++i)
    {
        std::cin >> jewels[i];
        if (jewels[i] > maxJewels)
        {
            maxJewels = jewels[i]; // 보석의 최대 개수 저장
        }
    }

    // 이진 탐색을 통해 보석의 최대 분배 개수를 찾기
    int left = 1, right = maxJewels, result = maxJewels;

    while (left <= right)
    {
        int mid = (left + right) / 2; // 학생에게 분배할 최대 보석 개수
        int totalStudents = 0;

        for (int i = 0; i < m; ++i)
        {
            // 각 종류의 보석을 학생들에게 최대 mid만큼 분배할 때 필요한 학생 수 계산
            totalStudents += (jewels[i] + mid - 1) / mid;
        }

        if (totalStudents <= n)
        {
            result = mid; // 필요한 학생 수가 n 이하이면, 더 작은 분배량을 시도
            right = mid - 1;
        }
        else
        {
            left = mid + 1; // 필요한 학생 수가 n보다 많으면, 더 큰 분배량을 시도
        }
    }

    std::cout << result << '\n';
    return 0;
}
