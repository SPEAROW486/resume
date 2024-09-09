#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 6236

int n, m;
std::vector<int> v;

bool check(int mid)
{
    int cnt = 1; // 인출 횟수
    int sum = 0; // 현재 인출 후 사용 금액

    for (int i = 0; i < n; ++i)
    {
        // 만약 현재 금액에서 더 쓸 수 없으면, 다시 인출
        if (sum + v[i] > mid)
        {
            cnt++;      // 인출 횟수 증가
            sum = v[i]; // 새로운 인출 금액으로 시작
        }
        else
        {
            sum += v[i]; // 현재 인출 금액에서 더 씀
        }

        // 만약 인출 횟수가 m번을 초과하면 실패
        if (cnt > m)
        {
            return false;
        }
    }
    return true; // m번 이하로 인출 가능
}

int main()
{
    FASTIO;
    std::cin >> n >> m;

    int left = 0;
    int right = 0;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);

        left = std::max(left, tmp); // 인출 금액의 최소값은 가장 큰 지출
        right += tmp;               // 인출 금액의 최대값은 모든 금액을 한 번에 인출
    }

    int result = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        // mid 금액으로 m번 이하로 인출 가능한지 체크
        if (check(mid))
        {
            result = mid; // 가능하면 결과 저장
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << result << "\n";

    // int nn;
    // std::cin >> nn;
    return 0;
}
