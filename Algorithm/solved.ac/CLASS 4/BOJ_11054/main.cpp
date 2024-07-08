
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

constexpr int MAX = 1001; // 1001;
int n;
int sequence[MAX];
int lis[MAX]; // lis[i] = 1부터 i번째 요소까지에 가장 긴 증가하는 부분 수열
int lds[MAX]; // lis[i] = i번째 요소부터 n번째 요소까지 가장 긴 감소하는 부분 수열?

int main()
{
    FASTIO;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> sequence[i];
        lis[i] = 1;
        lds[i] = 1;
    }

    // j는 양쪽 끝단
    // 증가면 1부터
    // 감소면 n부터
    // i가 움직이는거임
    // 그렇게해서 j~ i까지의 구간을 검사하는거고
    // 이번 구간에서도 조건을 충족하면 이전에 충족했던 구간 값에 +1을 해서 갱신하는 구조.

    // 1 2 3 4 5 6
    // 1과 1
    // 2와 1
    // 3과 1, 3과 2

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i - 1; ++j)
        {
            if (sequence[j] < sequence[i])
            {
                lis[i] = std::max(lis[i], lis[j] + 1);
            }
        }
    }

    // 6 5 4 3 2 1
    // 1과 1
    // 2와 1
    // 3과 1, 3과 2를 이런식으로 비교
    for (int i = n; i >= 1; --i)
    {
        for (int j = n; j > i; --j)
        {
            if (sequence[i] > sequence[j])
            {
                lds[i] = std::max(lds[i], lds[j] + 1);
            }
        }
    }

    int max_length = 0;
    for (int i = 1; i <= n; ++i)
    {
        max_length = std::max(max_length, lis[i] + lds[i] - 1);
    }

    std::cout << max_length;

    // int nn;
    // std::cin >> nn;

    return 0;
}