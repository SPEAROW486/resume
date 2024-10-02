#include <bits/stdc++.h>
#define FASTIO                             \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)

// BOJ : 7571

int main()
{
    FASTIO;

    int n, m;
    std::cin >> n >> m;

    std::vector<int> x_coords(m), y_coords(m);

    // 모든 점의 x, y 좌표 입력
    for (int i = 0; i < m; i++)
    {
        std::cin >> x_coords[i] >> y_coords[i];
    }

    // x, y 좌표를 각각 정렬
    std::sort(x_coords.begin(), x_coords.end());
    std::sort(y_coords.begin(), y_coords.end());

    // 중간 좌표 선택 (중앙값)
    int median_x = x_coords[m / 2];
    int median_y = y_coords[m / 2];

    // 각 좌표에서 중앙값까지의 거리 합 계산
    long long total_distance = 0;
    for (int i = 0; i < m; i++)
    {
        total_distance += std::abs(x_coords[i] - median_x);
        total_distance += std::abs(y_coords[i] - median_y);
    }

    // 결과 출력
    std::cout << total_distance << "\n";

    return 0;
}
