
#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2002
// 해시 맵

int main()
{
    FASTIO;

    int N;
    std::cin >> N;

    std::unordered_map<std::string, int> entryOrder;
    std::vector<std::string> exitOrder(N);

    // 입구 순서 기록
    for (int i = 0; i < N; ++i)
    {
        std::string car;
        std::cin >> car;
        entryOrder[car] = i;
    }

    // 출구 순서 기록
    for (int i = 0; i < N; ++i)
    {
        std::cin >> exitOrder[i];
    }

    int count = 0;

    // 추월 차량 수 계산
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (entryOrder[exitOrder[i]] > entryOrder[exitOrder[j]])
            {
                count++;
                break; // 이 차는 이미 추월이 되었으므로, 더 이상 확인할 필요 없음
            }
        }
    }

    std::cout << count << std::endl;

    // int nn;
    // std::cin >> nn;

    return 0;
}