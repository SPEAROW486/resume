#include <bits/stdc++.h>

#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 2304
// 스택을 이용한 면적 계산

constexpr int MAX = 1001;

int main()
{
    FASTIO;

    int n;
    std::cin >> n;

    int max_pos = 0;
    int max_height = 0;
    std::vector<int> v(MAX);
    for (int i = 0; i < n; ++i)
    {
        int l, h;
        std::cin >> l >> h;
        v[l] = h;

        if (h > max_height)
        {
            max_height = h;
            max_pos = l;
        }
    }

    int area = 0;
    int left = 0;

    // 왼쪽부터 가장 큰 기둥까지 영역 쪼개고
    // 그 안에서 가장 큰 기둥의 높이를 갱신해가면서 더한다.
    // 기둥이 없는 구간의 v[i] = 0이므로 기존값으로 계속 더해나가면됨.
    for (int i = 0; i < max_pos; ++i)
    {
        left = std::max(left, v[i]);
        area += left;
    }

    int right = 0;
    for (int i = MAX; i > max_pos; --i)
    {
        right = std::max(right, v[i]);
        area += right;
    }

    std::cout << area + max_height << "\n";

    // int nn;
    // std::cin >> nn;

    return 0;
}
